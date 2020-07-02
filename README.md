# VIP

Vi by Pyzozord (my IRC nickname), Very Important Program, Vi with Plugins, Vi Perfected.

VIP is my custom editor derived from [nex/nvi 1.80](https://repo.or.cz/nvi.git) aiming at editing efficiency and execution perfomance and tries to follow [suckless philosopy](https://suckless.org/philosophy/).

What *will* distinguish VIP is it's extremly simple and powerful plugin system based on unix pipelines and JSON format allowing for pipes to be written in any programming language capable of reading JSON text from stdin and producing JSON text on stdout.

### How to
1. You need to have libdb, libtre and libtre-dev available on your system
1. Navigate to ./build.me/
1. Run ./build.sh

### Roadmap
- [x] clone nex/nvi
- [x] remove gtk, motif, perl, ipc and docs
- [x] remove included db3 and regexp source coude, use libs instead
- [x] add support for widechars
- [ ] clean up unused build flags and related code
- [ ] clean up build system
- [ ] update code to C18
- [ ] pipe based plugin system

### Ideas for features
1. Vi commands n and N always go the same direction regardless of / or ? search direction
1. Better support for indentation
1. Readline for : and / commands
1. Break-wrap inserting new line characters (and autoindenting) next line
1. Align text command/motion moving a part of line to the center, left, rigt, before first char, after last char
1. Display first line with smaller indentation above screen until no text with no identation
