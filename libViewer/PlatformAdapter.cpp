#include "PlatformAdapter.h"
#include <cstdio>
#include <cstring>

PlatformAdapter* PlatformAdapter::adapter = 0;

PlatformAdapter::PlatformAdapter()
{
}

PlatformAdapter::~PlatformAdapter()
{
}

const char *PlatformAdapter::loadAsset(const char *filename, size_t *size)
{
    size_t filesize;
    FILE* f = fopen(filename, "rb");
    if(!f) {
        P3D_LOGE("Unable to load asset: %s", filename);
        return 0;
    }
    fseek(f, 0L, SEEK_END);
    filesize = ftell(f);
    fseek(f, 0L, SEEK_SET);
    char *data;
    if(size)
    {
        *size = filesize;
        data = new char[filesize];
    }
    else
    {
        data = new char[filesize + 1];
    }
    fread(data, filesize, 1, f);
    fclose(f);
    if(!size)
    {
        data[filesize] = 0;
    }
    return data;
}

void PlatformAdapter::logFunc(LogLevel level, const char *func, const char *format, ...)
{
    va_list args;
    va_start(args, format);

    // try to extract tag (c++ class)
    char* tag_buf = new char[strlen(func) + 1];
    char* tag = tag_buf;
    strcpy(tag, func);
    char* pos = strstr(tag, "::");
    if(pos)
    {
        *pos = 0;
        pos = strchr(tag, ' ');
        if(pos)
        {
            tag = ++pos;
        }
    }

    logTag(level, tag, format, args);

    va_end(args);
    delete [] tag_buf;
}

void PlatformAdapter::logTag(LogLevel level, const char *tag, const char *format, va_list args)
{
    FILE* out = stdout;

    switch(level)
    {
    case LOG_DEBUG:
        fprintf(out, "D ");
        break;
    case LOG_ERROR:
        out = stderr;
        fprintf(out, "E ");
        break;
    default:
        fprintf(out, "U ");
        break;
    }

    fprintf(out, "%s: ", tag);
    vfprintf(out, format, args);
    fprintf(out, "\n");
    fflush(out);
}
