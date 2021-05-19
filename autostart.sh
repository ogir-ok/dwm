#!/bin/sh
wmname LG3D &
feh --bg-scale ~/dwm/wallpaper.jpg &
python ~/dwm/status.py &
dunst &
QT_STYLE_OVERRIDE=gtk dropboxd &
guake &
xfce4-power-manager &
volumeicon &

slack &
telegram-desktop &
teams &

setxkbmap -layout "us,ru,ua" -option "grp:alt_shift_toggle"

xxkb &
nm-applet &
udiskie -t &
dropbox &
thunderbird &
twmnd &
gxkb &
conky &
flameshot &

google-chrome-stable &
pycharm &
