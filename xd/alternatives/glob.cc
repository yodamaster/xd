#include "alternatives.ih"

void Alternatives::glob(string dir, std::set<pair<size_t, size_t> > &stored)
try
{
    for_each(d_command.begin(), d_command.end(),
            FnWrap1c<string const &, string &>(addPath, dir));

    dir.resize(dir.length() - 1);   // remove trailing /

    msg() << "Passing `" << dir << "' to glob" << info;

    Glob glob(dir, Glob::NOSORT, Glob::DEFAULT);

    GlobContext context = {stored, *this};

    for_each(glob.begin(), glob.end(), 
             FnWrap1c<char const *, GlobContext &>(globFilter, context));
}
catch (Errno const &err)      // to catch the exception from glob
{}
