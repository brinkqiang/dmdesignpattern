
// Copyright (c) 2018 brinkqiang (brink.qiang@gmail.com)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef __DMFILE_H_INCLUDE__
#define __DMFILE_H_INCLUDE__

#include <memory>
#include <stdexcept>
#include <cstdio>
#include <string>

struct FileDescriptorDeleter
{
    inline void operator()(FILE *f) const
    {
        if (f)
        {
            fclose(f);
        }
    }
};

static std::string DMLoadFile(const char *fname)
{
    std::unique_ptr<FILE, FileDescriptorDeleter> fptr{fopen(fname, "rb")};
    if (!fptr)
    {
        throw std::runtime_error{"can't open file"};
    }
    fseek(fptr.get(), 0, SEEK_END);
    auto size = ftell(fptr.get());
    fseek(fptr.get(), 0, SEEK_SET);
    std::string output;
    output.resize(size);
    fread(&output.front(), 1, size, fptr.get());
    return output;
}

#endif // __DMFILE_H_INCLUDE__
