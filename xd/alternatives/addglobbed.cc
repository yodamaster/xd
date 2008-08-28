//#include <stdio.h> 
//#include "alternatives.ih"
//
//void Alternatives::add_globbed(const glob_t &glob_struct)
//{
//    if (!glob_struct.gl_pathc)      // any elements globbed ?
//        return;             // no, inform the caller
//
//    register char
//    *cp;
//    struct stat
//    buf;
//
//    for (register int index = 0; (cp =  glob_struct.gl_pathv[index]); index++)
//    {
//    if
//    (
//        !stat(cp, &buf)     // stat succeeds
//        &&
//        S_ISDIR(buf.st_mode)    // and it's a dir
//    )
//    {
//        if
//        (
//        dirsparam == Config::unique     // unique requested
//        &&
//        lookup(buf.st_ino, buf.st_dev)    // file already here
//        )
//        continue;               // then don't store
//
//        n++;                    // store: increase n
//        id = (Id *)realloc(id, n * sizeof(Id)); // make room
//
//        id[n - 1].inode = buf.st_ino;       // and store
//        id[n - 1].device = buf.st_dev;
//
//        push_back(cp);                // add the name
//    }
//    }
//}   
//    
