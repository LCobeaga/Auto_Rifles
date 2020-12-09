Auto Rifles
=====

![pretty shot](https://user-images.githubusercontent.com/44830532/101670791-7ca0e280-3a08-11eb-83ae-b84338f49ab7.jpg)

###### This is a Re-draw of Shadow Price with significant structural and aesthetic improvements that I made over the summer of 2020. It is now to-scale compared to in Destiny and much easier to edit. I plan to make all the other variants of stocks, barrels, and frames seen in the game. Internally, it is still BLDC flywheels and solenoid pusher, but now uses a 16 bit display ammo counter, and includes select fire. It also uses hardware to hold the blaster toghether, unlike the original which was mostly glued together. As a result, most visual components are separate parts, so even without paint the blaster should look very nice, and allows for color swaps if multiple aesthetic components are printed. 

#### NOTES: 
STLs did not save in correct orientation, but all parts have an obvious optimal print direction. 
Directories are poorly named, V1 is the version I printed that only works with very thin motors and lacks all optimizations (mostly in wire routing) no reason to print it.
V2 works for all motors that have a cage designed and includes all optimised wire routings and rigidity changes.

### HARDWARE
#### MECHANICAL
- Six 5mm x 400mm carbon fiber rods
- Five M3 x 8mm heatset inserts
- Three M2 x 4mm heatset inserts
- Five 10mm Nerf style screw
- Four M3 x 12 screws (I used hex socket)
- One M3 x 8 screw
- Four pen springs (one for trigger, two for mag release, and one for priming rod play feature)
- About 1 inch (30mm) of half inch or 14mm PVC pipe (to straighten dart as it leaves the flywheels)
- Electrical or Painters tape (to center and hold pipe at base of barrel)
- ~Four 1kg spools of filament (more if using multiple colors)
#### ELECTRICAL
- One 35mm solenoid 
- Two 2300KV brushless motors (currently supports 2204 and 1806)
- Two ESCs matching motor amperage draw
- One XT-60 (or preffered) male battery connector
- Two 6mm surface mount (or breadboard compatible) pushbutton switch
- Two D2F-01L3 momentary limit switches (I used the rounded lever)
- One MOSFET or pre-built mosfet board 
- One 10kΩ resistor (only if using raw MOSFET)
- One 10kΩ potentiometer
- One 32 x 128 I2C OLED display (https://www.dfrobot.com/product-2019.html this is the only one that I know works, but any with the same shape would work too)
- One Arduino Pro Mini 
- High Amperage wires for battery to MOSFET and ESCs
- Small wires for Arduino Connections
- OPTIONAL: JST or other connector type for removeable connections (good for troubleshooting)
- OPTIONAL: Solderable breadboard/raw PCB for wire management

### WIRING DIAGRAM

![Auto Rifle](https://user-images.githubusercontent.com/44830532/100831142-f5f17180-3419-11eb-8df8-56b378fbe148.png)

### ASSEMBLY 

1. Glue together the two handle halves (use the lower and knuckle guard bottom to align)

![image](https://user-images.githubusercontent.com/44830532/100831321-61d3da00-341a-11eb-89f6-37b443c72958.png)

2. Glue handle into the lower

![image](https://user-images.githubusercontent.com/44830532/100831543-d870d780-341a-11eb-9546-a05084cc138b.png)

3. Glue details into lower

![image](https://user-images.githubusercontent.com/44830532/100831768-45846d00-341b-11eb-9f17-343f00e5bf6a.png)

![image](https://user-images.githubusercontent.com/44830532/100831834-6220a500-341b-11eb-9ddc-ae0c7ab56fa1.png)

4. Glue lower covers to lower (make sure to have them align with the cut out for the solenoid

![image](https://user-images.githubusercontent.com/44830532/100832010-cd6a7700-341b-11eb-96bf-ea5e6889c8fb.png)

5. Glue lower filler into lower (make sure it is pushed all the way in)
![image](https://user-images.githubusercontent.com/44830532/100832188-3b16a300-341c-11eb-8f8c-1df99ee7905d.png)

6. Glue together the two knuckle guard pieces

![image](https://user-images.githubusercontent.com/44830532/100833157-37841b80-341e-11eb-97a4-1380ac1c1b8b.png)

7. Slot mag tooth with spring into lower, slot mag release into the handle, and place the lever into the lower from below

![image](https://user-images.githubusercontent.com/44830532/100833415-c85af700-341e-11eb-9c12-a292b9202a5d.png)

8. Snap the handle cover into place by rotating it in about the trigger guard

![image](https://user-images.githubusercontent.com/44830532/100833796-854d5380-341f-11eb-81ac-1885832c72d3.png)

9. Slot top of knuckle guard into lower, around the lever and mag release, then slot the tab into the recepticle in the handle and use a nerf screw to lock it in

![image](https://user-images.githubusercontent.com/44830532/100833534-00fad080-341f-11eb-9954-2608d9c0ae1f.png)

![image](https://user-images.githubusercontent.com/44830532/101677535-8c70f480-3a11-11eb-8e67-b2aa8da2fb40.png)

10. Press magwell covers into slots on either side (DO NOT GLUE, will need to remove later to access wires)

![image](https://user-images.githubusercontent.com/44830532/100833993-e8d78100-341f-11eb-911b-1e6659629204.png)

11. Slot in prime pin and prime, place spring behind prime so it will bounce back forward after getting pulled back (can also add some lubricant to smooth movement)

![image](https://user-images.githubusercontent.com/44830532/100834504-dc9ff380-3420-11eb-9cc9-0eb9b56819d8.png)

12. Glue detail parts into upper

![image](https://user-images.githubusercontent.com/44830532/100834968-b038a700-3421-11eb-9bb2-b8cccf8b6687.png)

13. Glue top picatiny into ammo counter (make sure bottom surface flush, the assembly slots into the upper)

![image](https://user-images.githubusercontent.com/44830532/100835236-263d0e00-3422-11eb-8a4c-2c0929051ec9.png)

14. Glue details into archway

![image](https://user-images.githubusercontent.com/44830532/100835408-72884e00-3422-11eb-90dd-1847392780c7.png)

15. Glue archway, top cover, and tail together (assembly called the frame)

![image](https://user-images.githubusercontent.com/44830532/100835535-ab282780-3422-11eb-9f76-68fc1c77fd10.png)

16. Cut a 400mm carbon fiber rod in half, and glue into top and bottom of stock filler. Align by first putting rods into upper and lower, then pushing stock filler into them. (all other parts can be optionally glued in, but I suggest against it)

![image](https://user-images.githubusercontent.com/44830532/100836300-e37c3580-3423-11eb-84bb-5b03aaf770fe.png)

The blue spirals are the M3 heat set inserts, can be added now or later, it does not matter

17. Glue the battery tray strap into the battery tray

![image](https://user-images.githubusercontent.com/44830532/101685225-5a18c480-3a1c-11eb-9b60-2d8413a3a7d2.png)

#### NO MORE GLUING FROM THIS POINT ON

18. Slot details into stock, and slide stock into dovetails. Place buttstock on back of stock filler. Screw one side of the stock panels into the standoff, then run standoff through the stock filler and screw on other side (they get centered by the upper so dont worry about lateral spacing)

![image](https://user-images.githubusercontent.com/44830532/100838057-a49baf00-3426-11eb-91e4-9c5d91b3de11.png)

19. Prepare locking lug by inserting the two M3 heat set inserts into the holes

![image](https://user-images.githubusercontent.com/44830532/100838215-e9bfe100-3426-11eb-8c9c-b319aa8e2ec4.png)

12. At this point you can begin wiring up the blaster, all electronics are housed in the upper other than the trigger switch. Below are photos of switch placement. Wire all switches as normally open, and the mag sensor switch will need the tabs cut down a little if they are too long (the mag sensor can also be flipped upside down if it registers more consistently)

![image](https://user-images.githubusercontent.com/44830532/100838628-a0bc5c80-3427-11eb-9a77-a733fe24120d.png)

![image](https://user-images.githubusercontent.com/44830532/100838706-c6e1fc80-3427-11eb-83b7-aeab3b006e63.png)

Parts removed for visual clarity

![image](https://user-images.githubusercontent.com/44830532/100838870-17595a00-3428-11eb-87d4-89a6100233dd.png)

Place a switch on both sides

![image](https://user-images.githubusercontent.com/44830532/100839000-5ab3c880-3428-11eb-9f80-835f64e22462.png)

Make sure not to glue in the OLED or it will make accessing the potentiometer harder

![image](https://user-images.githubusercontent.com/44830532/100839226-b8481500-3428-11eb-8ea7-39919bb2ecc6.png)

Route ESC and battery cables through this slot (it is ok for them to spill over into the open space, it is well above the magazine and gets covered up)

Add the final M3 Heat set insert into the hole marked by a red spiral

21. Once all the wiring is done, Screw together the flywheel cage assembly, and add in the three M2 heat set inserts to the cage (be careful to not melt through the top of the cage or it will interfere with the flywheels)

![image](https://user-images.githubusercontent.com/44830532/100839560-41f7e280-3429-11eb-936d-a8578cbbc039.png)

22. Slot trigger and trigger axle into the hole in the trigger well, and add the final pen spring in the hole behind it (rotate them in then push up until it snaps in place)

![image](https://user-images.githubusercontent.com/44830532/100839823-b9c60d00-3429-11eb-9f98-34b9513701c6.png)

23. Slot stock assembly into back of upper and lower, and screw in the top and bottom

![image](https://user-images.githubusercontent.com/44830532/100840310-8cc62a00-342a-11eb-905e-b6ac10299746.png)

24. Place the barrel filler over the lower filler and slot in another carbon fiber rod (DO NOT GLUE) making sure the rod is flush against the inside of the lower and the front of the barrel (you will have to cut the rod). Also dont forget to place the lock in the front slot of the barrel filler and the barrel rail in the slot on top

![image](https://user-images.githubusercontent.com/44830532/100842277-72418000-342d-11eb-86ad-dcf2cd7fb10d.png)

25. Place the center filler over the flywheel cage and lock it by slotting the locking lug from behind and another carbon fiber rod from the front. This rod should stick out a little at the front because it sticks into the barrel faceplate, so make sure to check its length and have it flush against the inner wall of the upper. Also screw it down with the longer M3 screws

![image](https://user-images.githubusercontent.com/44830532/100841849-bc763180-342c-11eb-9385-3f05aaa74947.png)

26. Wrap tape around the small length of PVC and push it down the barrel so it is flush with the front of the flywheel cage

![barrel insert](https://user-images.githubusercontent.com/44830532/101695266-285a2a80-3a29-11eb-90c2-b01ce03eadd6.jpg)

27. Once all the electronics are inside, snap the ammo counter cover into the upper by squeezing the sides, placing it into the cavity, teetering it back and snapping the sides out (make sure they snap past these tabs)
![image](https://user-images.githubusercontent.com/44830532/100840560-ec243a00-342a-11eb-966a-a8d2a526e5e5.png)

28. Slot ammo counter and picatiny assembly over the electronics and OLED (red arrow), then rotate the oled into the slot on the ammo counter and use the shorter M3 screw to lock it down (blue arrow)

![image](https://user-images.githubusercontent.com/44830532/101680433-8ed54d80-3a15-11eb-9743-acfa780f8f3e.png)

29. Snap the frame over the upper, it will lock in at the front, back, and slot over the cut out in the ammo counter

![image](https://user-images.githubusercontent.com/44830532/100842069-21318c00-342d-11eb-90c3-028dc23f57ba.png)

30. Snap in the top cowl and add the last Nerf screw to hold it down

![image](https://user-images.githubusercontent.com/44830532/100842180-4b834980-342d-11eb-8852-719566a8b59f.png)

31. Slot on the barrel clip, it will snap in place once in position

![image](https://user-images.githubusercontent.com/44830532/101683411-c5ad6280-3a19-11eb-94a1-1c267a2cebbd.png)

32. Stack up the three parts of the side panels and push a carbon fiber rod almost all the way through them, but dont go through the rectangular opening at the end

![image](https://user-images.githubusercontent.com/44830532/101681854-a6add100-3a17-11eb-9c56-9751db52ff0d.png)

33. Push the panel assembly through the barrel clip from the back, and once far enough the opening in the panel will lock over the arc pop-out in the upper and lower

![image](https://user-images.githubusercontent.com/44830532/101683185-79622280-3a19-11eb-95c0-a1edab62b032.png)

34. Slot on the barrel. It will mesh with the top and both panel carbon fiber rods, and sit flush against the barrel filler front surface and lower rod, so they all need to be at the correct length for this step (tip: if you have problems aligning the rods, push them into the barrel FIRST so you just press the assembly into position, slotting all the rods at the same time)

![image](https://user-images.githubusercontent.com/44830532/101684537-6e0ff680-3a1b-11eb-9a80-fd883376526b.png)

![barrel tips](https://user-images.githubusercontent.com/44830532/101684869-ea0a3e80-3a1b-11eb-8747-06bf60ce9cbd.jpg)

35. Screw on the muzzle, snap in the battery tray and lock it with the second barrel and you are done!

![image](https://user-images.githubusercontent.com/44830532/100842856-4e326e80-342e-11eb-9960-e8863c07d1b6.png)

## CODE

You will need four external libraries to run the code for this blaster. 

They are:
- JC button library https://github.com/JChristensen/JC_Button
  - built in pullup resistor commands, inversion, and debouncing
- Adafruit GFX and SSD1306 (downloadable thru arduino library manager)
  - controls OLED display with easy to understand commands
- Ammo counter (self written library, available in the code directory)
  - ammo counter code written by Monty Choy converted to a library
  
Current issues to work out:
- more descriptive interface with user

## CUSTOM PANELS

If you would like custom panels like the ones on my personal blaster (seen at the top of the read me) a step file is available in the STEP directory. 

The provided STEP includes the two panels as single, large parts and a new barrel clip that does not extend into the central cutout. 
As long as you dont fill in the hole for the rod, the slot in the back, or the cutouts that mesh with the barrel in the front, you can add anything you want to the panels. 
If your printer is not large enough for a full panel (like mine) you can make a design along where you plan to cut the panel, like the eagle head on my personal blaster.
Have fun with it and personalize your blaster to your tastes!

## Fusion File Downloads

https://drive.google.com/file/d/14dP4xmUzW5uqN5At8K1t4rPcA42P4aSs/view?usp=sharing 

File was too big to upload, but this is the base frame, i.e. the Shadow Price look alike

<a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/3.0/"><img alt="Creative Commons License" style="border-width:0" src="https://i.creativecommons.org/l/by-nc-sa/3.0/88x31.png" /></a><br />This work is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/3.0/">Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License</a>.
