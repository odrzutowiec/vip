😐 Goal 1: Readline: Replace default colon command line routines with gnu readline.

 1. ✅ feature: add readline make it execute commands
 2. ✅ bug: it exists after a command
 3. ✅ bug: it doesn't show text typed in the readline
 4. ✅ bug: it shows the readline prompt at the wrong place
 5. ✅ bug: it "eats" one key stroke if you don't wait for it to show up
 6. ✅ bug: it always waits for secound keystroke before showing prompt
 7. ✅ bug: somtimes letters from the file buffer get confused with the :command
 8. ✅ bug: it doesn't clear screen properly after entering the command
 9. ✅ bug: the cursor is not updating
10. ✅ bug: prompt is missing
11. ✅ bug: search doesn't work
12. ✅ bug: support for exiting :command mode with esc, ctrl-c and backspace
13. ❌ bug: esc can't be used because then meta keys don't work
14. ✅ feature: support for command history
15. ✅ feature: support for cedit option
16. ❌ feature: support for file completion and filec option
17. ✅ feature: support for ^V

👎 Goal 2: Motion - Introduce "reverse count" motion as in "c-2t)".

👎 Goal 2: Regex - replace musl TRE regex with Plan 9 regex


Well it's something...

# Presentation Plan

INTRO
1. Cover with ascii art VIP by Michal
2. Explanation on how to pronounce my name
3. Explain what is VIP and what my hack about
	My main code editor, use it almost exclusively at work
	Hack failed: 15/17 of 1 of 3 goals
4. Presentation agenda
	Not a lot to show, so history lesson instead

HISTORY
5. Of electronic computers
	turing
		worked on cracking enigma
		developed Universal Turing Machine, "turing-complete", 
		turing award
	1947 first transistor at bell labs
	1949 ENIAC
		first amercian electornic programmable microcomputer
		used mostly for army
		buttons
		punchcards
	1959 MOS transistor at bell labs
	1965 PDP-7 
		Papertape,
		Punchcards,
		Teletypes,
		Line printer
		Keyboard
	1970 PDP-11
		video display terminals
		floppy disks
	1977 Apple 2
	1981 IBM PC
	1991 WWW available for everyone
7. Of operating systems
	1964 MULTICS
	1969 UNIX
	1972 C
	1977 BSD
	1981 DOS 
	1983 GNU
	1985 Windows
	1989 NeXT
	1991 Linux
	2001 MacOS
8. Of code editors
	1969 Ed
	1976 Ex/Vi
	1976 Emacs
	1991 Vim
	1994 Nex/Nvi
	1997 Visual Studio
	2001 Eclipse
	2015 Visual Studio Code
	2020 VIP

VIP
9. Why I'm working on VIP
	Worked on and off in vim since I was 15, eventually too complex
	The one editor to rule them all for the rest of my life
	Praticing C to have deeper understanding of computers
10. Adding readline
	What is readline
	How Nvi command mode works normally
	Why adding readline is an improvement
11. What were the challanges
	Integrating readline and ncurses
	Making readline use nvi routines for input and rendering
	Navigating old, obscure C
12. What did I learn
	Sharpened my GDB debugging skills
	Learn a lot about readline
	Read a bit about ncurses
	Sharpened navigating and understanding unfamiliar code skills
	Top-down vs bottom-up approaches to solving problemes
13. DEMO
	Boring demo, most time spent solving bugs to make it work like original
	simple commands
	  nvi :q - old vi joke 
	  vip :q - works the same
	previous
	  vip :%s/.//g - oops, undo, try again, ^P doesn't work, need to type command again
	  vip :%s/.//g - oops, undu, try again, ^P works, also ^N, ^R
	command edit
	  nvi :^E - command line editing nvi style
	  vip :^E - still works!
	  vip :command ^A ^E, ^[B, ^[F, ^[W, ^[L - works!
	  nvi :command ^A ^E, ^[B, ^[F, ^[W, ^[L - doesn't work
	file completion
	  nvi :^F - file completion
	  vip :^F - nope, still working on it

OUTRO
13. Future plans for VIP
	Update everything to C17
	Replace autotools building system with Cmake
	Build a statc binary with little or no dynamic dependencies
	Pipe based plugin system - VI with Plugins
	
	
	
	
# Presentation Text

1. Hi, my name is Michał and I'll be presenting my project which I call Vip.

2. First things first. You can pronounce my name by spelling Me-How in enlish. But don't worry too much, if you don't get it right I won't mind as long as you made an effort to try. I am originally from Poland but I live over five years now in The Netherlands working as a Frontend Developer and spending most of my days programming in JavaScript and React.

3. So my project, Vip, is a code editor. The name Vip stands for Very Important Program because it's very important to me. Also it's a play on words but more about that later. I use Vip every day almost exclusively at work and when working on personal projects. I actually use Vip to work on Vip. For this hack I had three goals and I faild at all three of them. Well I came close on the first goal and It's probably one of the more diffcult ones but I can't say I reached my goals. Nontheless I'm very happy with the progess I made.

4. Because of that I don't really have much to demo. So I thought it would be fun to provide some historical context to ground the project. I think it will help you understand what is Vip, where it came form and where it's going. I wrote this presentation with a non techinical audience in mind so please excus me me any gross oversimplifications. The presentation is divided into four chapters: Introduction, that's where we are right now. History, where I'll describe a brief history of electornical computers, operating systems and finally code editors. Vip, where I'll explain what exactly I was trying to do and demo the resluts. And a brief outro explaining my plans for the future of Vip. 

5. Comptuers existied before they were electornical. Charles Babbage is considered the father of the computer thanks to his revolutionary Difference Engine, a mechnical calculator he developed in 1832. Later electromechanical computers were used often by arme. The first electronic digital programmable computer ENIAC was developed in 1949. ENIAC stands for Electronic Numerical Integrator and Computer. It was the first computer to be "turing-complete". Alan Turing was a genius mathematician working on cracking the german cypher Engima, during the second world war. While working on that problem he developed a hypothetical Universal Machine cabale of simulating itself. That's where the "turing-complete" term comes from. Turing's research was so infulential that today we celebrate Turing Awards which are essentially Nobel Prizes for computer scientists. The ENIAC was a big device full of diodes and buttons that required it's own room and multiple operators to watch the diodes, press the buttons and feed it so called punchcards. Punchcards were one of the earlierst methods of storing computer instructions and data in a physical form. The were essentially small pieces of paper with 80x20 cells. A hole in the cell represented a value of 1 while hole missing represented 0. Today in 2021 the tradition to keep your code 80 characters long is still alive and very popular. Those big, room-filling computers were called the Mainframes and looked and function somewhat simliar to todays racks of servers in data centers. The 1970s was the mainframe era however so called microcomputers were being developed. Micros had somehow misleading name to the modern ear. They were about the size of nice closet. In 1965 the PDP-7 micro was released. It had a punchcard reader and teletype ports. Teletypes were typewriters connected to the computer, so that they could issue commands to the computer and print back the results. Five years later in 1970 a PDP-11 was release with ports for video display terminals which were essentially a digital version of a teleprinter. After micros came the 80s, the time of the personal computer. In 1977 Steave Jobs released Apple 2. In 1981 an IBM PC was released, and finally in 1991 the world wide web was opened for everyone.

6. Very early on computer started needing operating systems. A resident software that convinetly served as a layer of abstraction between the hardware and the application. In the 70s the concept of timesharing was born out of necessity. Multiple people were often connected via teletypes to a single mainframe or micro and did not want to wait long for their results. One of such early timesharing operating systems was called MULTICS Multiplexed Information and Computing Service, and it's development started in 1964 at Bell Labs. The research center of AT&T. It had many innovations and shaped modern operating systems in many ways. However it was a big and complex project, which was eventually abandoned in 1969. Some of the Bell Lab scientistcs including Ken Thompson and Dennis Ritchie decided to try develop operating system again, using some of the great ideas of MULTICS but make it simpler and smaller. They called it Uniplexed Information and Computing Service, UNIX. In 1972 the same scientics developed the C programming language and rewrote UNIX in C. In 1977 scientists in the University of California Berkely developed their own version of UNIX "forkng" the original UNIX code. Forking is a programming pratice where you take the original codebase and apply modifications to it making it a separate project. It's done a lot in computer world and some modern software has very deep roots. In 1981 Microsoft DOS was created by Bill Gates, in 1983 GNU free software foundation was founded by Ritchard Stallman. GNU is a recursive acronym and it stands for GNU is Not Unix. It's nonprofit organization for passionates developing free software. Free as in freedom not free of charge. In 1985 Windows was developed based on the DOS code. In 1989 NeXT operating system was developed based on the BSD. In 1991 Linux kernel was developed by Linus Torvald as a UNIX compatible operating system kernel and put together with GNU to create what we today colloquially know as the Linux operating system. IN 2001 MacOS was developed based on the NeXT operating system. 

8. Code editors were necessary as long as code had to be written. The earliest code was written on punchcards by the computer operators. Later code was written with teletypes and terminals using a software code editor, usually provided as part of the operating system. One of the first editors was developed at Bell Labs as part of the UNIX in 1969 and it was called Ed. Ed was line editor with very simple and terse interface to save on the paper and ink in teletypes. In 1976 in the time of digital terminals an improved version of Ed was created called Ex. Ex had to modes, the traditional line editting mode and new visual mode. That editor was sometimes called Ex/Vi Vi or VEE for the visual mode. We still use this editor today but we call it just Vi even though for compatibility reasons it still has the same two modes. Vi is sometimes called a modal text editor because it has different modes. By default, in the "normal" mode your key pressess do not insert characters to the file, instead they issue different commands to the editor. One such command for example is "i" for insert. That command will change the mode of the editor to insert mode, where your keyboard input will insert new characters into the opend file. To return to the normal mode you need to press Esc. The same year first version of Emacs is released by Richard Stallman the founder of GNU. Later version, GNU Emacs, is still used by a lot of developers today as their main code editing tool. In 1991 VIM was created by a dutchman Bram Moolenaar. The name stands for Vi IMproved. It is a mostly compatible clone of VI with many improvements. It is one of the most popular code editors today, certainly in the top five with GNU Emacs and Visual Studio Code. In 1991 a vi replacement for BSD 4.4 was develop called Nex/Nvi or just Nvi. It had different approach then VIM, it has limited itself to only most fundamental features and full compatiblity with Vi. This is the code my editor is forked from. In 1997 Microsoft Visual Studio was released. The concept of IDE an Integrated Development Environment was getting popular. An IDE is a set of tools including code editor, compiler, debugger working together as a single system. IN 2001 Eclipse was released. Lastly the latest adding in popular code editors is Visual Studio Code which is a hybrid of a code editor and a IDE implemented in web technologies (that editor is actually a website in a window). In 2020 I have began my work on Vip.

9. So you know already that Vip is a code editor based on Nvi which originaly was released as part of the BSD operating system. But why am I working on such an old technology. Well there is a coplue of reasons. I worked on and off in vim since I was 15, that's about 15 years ago now. Last 5 or so years I used VIM as my main code editor. It's a big and complex piece of software and even after 15 years I was still learning alot about it. At some point I realised that is too complex for me and I am willing to sacrifice some of the convenience it provides for simplicity. I think I will be writing code for the rest of my life. And when I realised that I thought that I better find a tool that I like and that works well for me. The one editor to rule them all. Obviously I need to have full and deep understanding of it and be able to change anything I want about it. Nvi was the perfect starting point, it is simple enough for me to eventually understand fully it's code base and small enough for me to change it. It also has the most important modern features such as emoijs (wide characters). The last and the most important reason why I decided to work on my own editor is that I wanted to pratice C. C is a simple programming language that doesn't hide away the underlaying architecture of the operating system and the hardware. This pet project lets me pratice and furether my skills and understanding of how computers actually work.

10. So what exactly I wanted to do with the editor? I wanted to add a library called readline. Readline is GNU library providing convenient routines for inserting commands. It lets you go back to previous command and edit the current command in an easy way. It also has other features I could make use of in the future. Normally in Nvi the command mode has very limited capabilities of editing the current command, it can be annyoing sometimes if you made a topo and didn't notice it, you'll need to enter the entire command again.

11. I spent 90% of the time in the GDB, the GNU debugger trying to understand how Nvi's input, text processing and rendering routines worked, and later after I added readline why it's not working or acting weird. That was mostly it, not a lot of hacking, mostly debugging. Nvi is based on ncurses, ncurses is library for managing virtual terminals, it lets you draw on screen with text. It was really difficult to find a way to make nvi, ncurses and readline all agree and cooperate, I think that was the biggest challange in this project. Also Nvi's code is quite complex it has a lot of edge cases, support for many operating systems and many optimizations. And it's been written in C sstandard from 1989, which is a bit less refined then todays version.

12. I've learned few new things about debugging in GDB. I've learned a lot about readline and few things about ncurses. I've pratcited alot my skills of understanding and maintaing legacy projects. I also realised that even that I like top-down approach to solving problems sometimes, especially in limited time, it's much more efficinet to find a way that works first and understand it later.

13. So this is time for the demo, it's going to be boring because I spent most of my time solving bugs to make readline act like nvi was acting before. But here we go. You can see what keys I'm pressing on the keyboard, watch them carefully. There is an old joke, but still very popular due to popularti of VIM that it's impossible to quit it. This stems from the fact that it is a modal editor and most people who don't use vim have no concept of modal editing. So first I'll show you how to exit nvi, and then prove that vip it works exactly the same. We need to enter the editor first, by default we land in the normal mode. Then we press colon to enter a command mode and type q and press enter to issue a quit command.  Here you can see me the same doing the same thing in Vip. It works, all good so far. Okay, next lets try something more exciting. Let's say I was working on this file for a while and I want to remove the space at the begging of some of the lines. I'm entering the command mode again and typing a global substitue command. I enter the command, and everything is gone! I made a typo in my comand. Now I need to undo the last change and trying entering the command again. I enter the command mode and it's empty, I need to type the entire command again. Ctrl-P and Ctlr-N don't work. Now let's try the Vip version. I enter the command, I make the same typo, the file is gone, I need to undo. And then enter the command mode again. Notice that this time when I press ctrl-p it will prefill the command line with the previous command. I can now edit the command, correct the mistake and try again. Antother big thing to notice here is that I am using ctrl-a and contrl-e as well as alt-b and alt-f and other key bindings to edit the command on the fly. That is not possible in normal Nvi. That was pretty much it. Readline has more features and I'll be able to take adventage of all of them but it was hard enough to make this work, it literally took me 4 days 8h per day to get to this point. Anyway I'm really happy with this. It was really challanging but I proved to myself I can do anything I want with this editor.

14. My plans for the future of Vip are big. I want to update the entire codebase to the latest C17 standard, replace the GNU autotools building system with CMake, change the building process to statically link all libraries so that Vip can be distributed as a single binary and finally introduce and Inter Process Communicatino system based on Unix Pipes so that I can write plugins to Vip in any language or technology able to read and write text. It will then earn it's second name VI with Plugins. Thank you for taking the time to watch my presentation I hope you learned something new or at least enjoyed yourself.




Hello my name is michal and I'll be presenting my project which I call vip.
I am from Poland but I live in the Netherlands now.
I spend most of the time working in JavaScript and react.
So Vip is a code editor. The name vip stands for very important program.
I use vip every day at work. And I actually use vip to work on vip.
For this hack I had three goals and I failed at all three.
Well I came close on the first goal which is probably the most difficult one, but I can't say that I reached my goals.
Nontheless I am very happy with the progress.
So there is a joke that it's impossible to quit vi, so let's try that first.
You can see what keys I'm pressing so watch them carefully.
Ok so first I am opening Nvi, then entering the command code with the colon key and finally typing q to issue the quit command.
So let's do the same in Vip, colon command, q, enter and it worked, great.
Okay so let's try something more difficult, let's say I have this file and I want to remove the first character in all lines.
Ok so I'm entering the command mode, I'm typing in the substitute command...
And I made a typo, everything is gone. I need to undo now. Enter the command mode again and type in the entire command again.
Let's try the same thing in Vip. I enter the command...
Everything is gone, so I undo and enter the command mode again.
This time I can press ctrl-p and ctrl-n to cycle through previously issued commands.
I can also edit the command on the fly with ctrl-a ctrl-e, alt-b, alt-f, alt-backspace and ctrl-w.
There is only one bug at the moment, the escape key doesn't exit the command mode.
Nvi doesn't handle meta keys well, for example alt-b is interpreted as two key presses: escape, then b.
Because of that I have to ignore the escape key for now.
It is possible to fix this but it will require refactoring of the internal input routines in nvi.
So I wrote about 4 pages of history on computers, operating systems and editor, 
but I can see now there is nowhere near enough time to read any of that so thank you very much for watching.
