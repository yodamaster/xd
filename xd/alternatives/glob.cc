#include "alternatives.ih"

void Alternatives::glob(string dir, GlobContext &context)
try
{
    for_each(d_command.begin(), d_command.end(),    // add */ to each cmd arg
                        FnWrap::unary(addPath, dir));

    dir.resize(dir.length() - 1);                   // remove trailing /

    imsg << "Passing `" << dir << "' to glob" << endl;

    Glob glob(dir, Glob::NOSORT, Glob::DEFAULT);    // find matching elements

    for_each(glob.begin(), glob.end(),              // accept unique dirs.
                         FnWrap::unary(globFilter, context));
}
catch (Errno const &err)      // to catch the exception from glob
{}