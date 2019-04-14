# PiHueEntertainment
An application that can utilise a webcam plugged into a Raspberry Pi (or Windows desktop) to output to Philips Hue Entertainment Areas.

## What does this mean?
This allows you to point a compatible camera at any screen or display and synchronise your Hue lights with it, regardless of where the content on the display is coming from. This means you no longer have to route content through a desktop running Hue Sync to have a dynamic room.

![Image of application in operation](https://giant.gfycat.com/GreedyCaringHackee.gif)

## Current capabilities
* A full UI to connect to a Hue Hub, select an entertainment area and view the camera input.
* Works on Windows desktops, Raspberry Pi (3B or B+ is recommended) and ASUS Tinker Board but is probably capable of many more platforms with some tweaking.

## Limitations
* Due to the limited power of the Raspberry Pi, it is only really capable of capturing at about 10fps, which is mostly fine for lighting.
* Camera latency could be an issue. I've only been using an old dashcam as a camera though, so this could just be down to the camera performance.
