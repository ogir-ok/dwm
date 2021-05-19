#!/bin/python
import os
import time
import subprocess
from datetime import datetime


def get_cmd_output(cmd):
    return subprocess.check_output(cmd)


class Widget(object):
    def get_status(self):
        raise NotImplemented()


class CmdWidget(Widget):
    def __init__(self, cmd):
        self.cmd = cmd

    def get_status(self):
        return get_cmd_output(self.cmd)


class WiFiWidget(CmdWidget):
    def __init__(self):
        self.cmd = "netctl-auto current"

    def get_status(self):
        status = super(WiFiWidget, self).get_status()
        return status.replace('wlp3s0-', '') or 'disconnected'


class BatWidget(Widget):
    def __init__(self, *a, **kwa):
        super(BatWidget, self).__init__(*a, **kwa)
        self.last_capacity = 100

    def get_status(self):
        status = get_cmd_output(['acpi', '-b']).decode()
        status = status.replace('Unknown, ', '')
        status = status.replace(' remaining', '')
        status = status.replace(' until charged', '')

        with open('/sys/class/power_supply/BAT1/capacity', 'r') as f:
            bat_capacity = int(f.read())

        if bat_capacity < 20 and self.last_capacity >= 20:
            os.system('notify-send -u normal "Battery power is lower than 20%"')

        if bat_capacity < 5 and self.last_capacity >= 5:
            os.system('notify-send -u critical "Battery power is lower than 5%"')

        self.last_capacity = bat_capacity

        return status.replace('Battery 0:', '').replace(' remaining', '').split(',')[-1]


class TimeWidget(Widget):
    def get_status(self):
        return datetime.now().strftime('%a, %d %b %H:%M')


WIDGETS = [
    #CmdWidget('deadbeef --nowplaying "%a - %t(%e/%l)"'),
    BatWidget(),
    #WiFiWidget(),
    #CmdWidget('xkb-switch', ),
    TimeWidget()
]


def loop_status():
    while True:
        try:
            status = ' '.join([w.get_status() for w in WIDGETS])
            subprocess.call(['xsetroot', '-name', status.replace('\n', '')])
            time.sleep(1)
        except Exception as e:
            raise


if __name__ == '__main__':
    loop_status()


