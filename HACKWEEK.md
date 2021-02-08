# Goals
1. Readline: Replace default colon command line routines with gnu readline.
2. Motion: Introduce "reverse count" motion as in "c-2t)".
3. Regex: (stretch goal) replace currently used musl libc's TRE regular expression library with Plan 9's regular expressions library. https://9fans.github.io/plan9port/unix/

# Readline tasks
1. ✅ Add readline make it execute commands
2. ✅ bug: it exists after a command
3. ✅ bug: it doesn't show text typed in the readline
4. bug: it shows the readline prompt at the wrong place
5. bug: it needs extra ":" colon sign at the beggining
