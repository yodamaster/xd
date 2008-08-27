#include "command.ih"

Command::Command(Config const &cf)
{
    char const
         *cp;
    register unsigned
        len;
    
    config = &cf;               // only a reference. no copy
    pattern = 0;                // initialize pattern to 0

    command = new char;         // initialize to empty str.
    *command = 0;
    len = 1;                // strlen(command)

    Arg &arg = Arg::instance();

    for                 // walk all arguments
    (
        register int index = 0;     // as long as there are any
             (cp = arg[index]);
                index++
    )
    {
        len += strlen(cp) + 1;      // new length of command
        command = (char *)realloc(command, len);
        strcat(command, cp);        // append the arg, and
        strcat(command, "/");       // append a '/' separator
    }
}                       // all args catenated

