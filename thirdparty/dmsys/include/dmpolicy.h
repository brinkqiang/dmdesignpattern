
#ifndef __DMPOLICY_H_INCLUDE__
#define __DMPOLICY_H_INCLUDE__

#include <locale>

#include "dmstl.h"
#include "dmfile.h"
#include "dmformat.h"
#include "dmerrordata.h"

#include "dmcsv_parser.hpp"
#include "dmcsv_writer.hpp"

class CLocalGuard
{
public:
    CLocalGuard()
    {
#ifdef WIN32
        m_oLocale = std::locale::global(std::locale(""));
#endif
    }

    ~CLocalGuard()
    {
#ifdef WIN32
        std::locale::global(m_oLocale);
#endif
    }

private:
#ifdef WIN32
    std::locale m_oLocale;
#endif
};

#define LOCAL_GUARD(x)  do{ CLocalGuard oLocalGuard; x;}while(0)

#ifdef WIN32
#define CONFIG_PATH_DELIMITER '\\'
#else
#define CONFIG_PATH_DELIMITER '/'
#endif

#ifndef CONFIG_FILE_NOTEXIST
#define CONFIG_FILE_NOTEXIST 1
#endif

#ifndef CONFIG_CSV_DELIM
#define CONFIG_CSV_DELIM ","
#endif

#endif // __DMPOLICY_H_INCLUDE__
