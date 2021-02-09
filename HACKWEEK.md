# Goals
1. Readline: Replace default colon command line routines with gnu readline.
2. Motion: Introduce "reverse count" motion as in "c-2t)".
3. Regex: (stretch goal) replace currently used musl libc's TRE regular expression library with Plan 9's regular expressions library. https://9fans.github.io/plan9port/unix/

# Goal 1: Readline
1. ✅ Add readline make it execute commands
2. ✅ bug: it exists after a command
3. ✅ bug: it doesn't show text typed in the readline
4. ✅ bug: it shows the readline prompt at the wrong place
5. ✅ bug: it "eats" one key stroke if you don't wait for it to show up
5. ✅ bug: it always waits for secound keystroke before showing prompt
6. bug: it doesn't clear screen properly after entering the command
7. feature: support for command history and cedit option
8. feature: support for file completion and filec option
