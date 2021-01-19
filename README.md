# VIP

Very Important Program, Vi with Plugins, Vi Perfected.

VIP is my custom editor derived from [nex/nvi 1.80](https://repo.or.cz/nvi.git) aiming at editing efficiency and execution perfomance and tries to follow [suckless philosopy](https://suckless.org/philosophy/).

What *will* distinguish VIP is it's extremly simple and powerful plugin system based on unix pipelines and JSON format allowing for pipes to be written in any programming language capable of reading JSON text from stdin and producing JSON text on stdout.

### How to
1. apt-get install libncursesw5-dev libdb-dev libtre-dev autotools-dev libtool
1. Navigate to ./build.me/
1. Run ./build.sh

There is also something else you need in step 1, but I'm not sure what at the moment. You can figure it out from the errors in step 3.

### Implemented features
1. Added "lr" option shortcut for "leftright" option.
1. Better support for indentation. Added "spacetabs" (shorthand "st") option. It makes the insert mode ^t and normal mode >> generate [tabstop] of spaces instead of a tab character.

### Ideas for features
1. Vi commands n and N always go the same direction regardless of / or ? search direction.
1. Readline for : and / commands.
1. Break-wrap inserting new line characters (and autoindenting) next line.
1. Align text command/motion moving a part of line to the center, left, rigt, before first char, after last char.
1. Display first line with smaller indentation above screen until no text with no identation.
1. "c-2t)", a "-" count for motions to count from the end (also "+" to make it consistant).
1. Visual selection mode.
1. Support for .viprc config file name.

### Technical roadmap
1. [x] Clone nex/nvi.
1. [x] Remove gtk, motif, perl, ipc and docs.
1. [x] Remove included db3 and regexp source coude, use libs instead.
1. [x] Add support for widechars.
1. [ ] Temporarly commit the configure script until the build system is converted to plain makefile.
1. [ ] Clean up unused build flags and related code.
1. [ ] Change build system to plain a makefile.
1. [ ] Update code to C18.
1. [ ] Static single binary builds.
1. [ ] Pipe based plugin system.
