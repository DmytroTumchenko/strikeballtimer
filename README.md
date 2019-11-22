# strikeballtimer
timer for military games


## Player's scenarios:
There are 3 sides. Each side should start counting for their side by pressing button with color of their team.
LED will change blinking to another color. After 1 minute after starting counting for some side 1 point wil be incremented to this side.
If another side will intercept point with timer and press button of their side timer will stop counting for previous team and will start counting for new one.
If some teammember will press button ones more after starting counting nothing will appear. This is "safer" for mistake of teammember.
Game will continue until game time left.
Timer is ready to use after activation by Admin and will start count for the team just after pressing button.

## Admin's scenarios:
Admin is able to:
- start game
- stop game
- set duration of the game

Changing setting is available via http from any mobile device witch is available after connection to the WiFi of the timer. Timer could be turned on/off to save energy.

## Features
- In case of lost of power Timer will save currect stats to the EEPROM (energy non-volatile memory)
- OLED display will show current status for all teams (could be adjusted by admin)
- hide/show results of counting for players (to save intrigue till the end of the game end)
