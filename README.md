# WalkingTurtles

Made in two evenings. 8-12 hours.

Task1
=====
In root You can find RestructString.cpp and RestructString.exe:

For Your comfort You can run EXE file and look how it works, and check for details in CPP file.

Task2
=====
Classes description:
=====
WTNest
=====
All custom settings can be set in "Config" and "FX" categories.
- In Config You can set:
1. Nest number;
2. Button that activates this Nest;
3. Class of AWTAICharacter that should spawn from Nest;
4. BehaviorTree that should use "Turtle";
5. Destination Actor - can be any AActor on scene;
- In FX you can set:
1. SoundCue and NiagaraSystem that should play when "Turtle" spawn;

WTButton
=====
Has only FX settings where You can set ButtonPress sound;

WTAICharacter
=====
In Config You can set sounds and VFX when Character Runs and Destroys;

Known problems
=====
+ Doesn't have any input notice on screen.
+ When Press E You can interact with buttons. Very simple interact system. Works only with WTButtons.
+ Have no time to refactor code :(
+ Didn't create more Custom Tasks for BehaviorTree. So many dirty workarounds in there.
+ Some Classes names may not have WT prefix. Night work, tired brain...
