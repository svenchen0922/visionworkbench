// __BEGIN_LICENSE__
// 
// Copyright (C) 2006 United States Government as represented by the
// Administrator of the National Aeronautics and Space Administration
// (NASA).  All Rights Reserved.
// 
// Copyright 2006 Carnegie Mellon University. All rights reserved.
// 
// This software is distributed under the NASA Open Source Agreement
// (NOSA), version 1.3.  The NOSA has been approved by the Open Source
// Initiative.  See the file COPYING at the top of the distribution
// directory tree for the complete NOSA document.
// 
// THE SUBJECT SOFTWARE IS PROVIDED "AS IS" WITHOUT ANY WARRANTY OF ANY
// KIND, EITHER EXPRESSED, IMPLIED, OR STATUTORY, INCLUDING, BUT NOT
// LIMITED TO, ANY WARRANTY THAT THE SUBJECT SOFTWARE WILL CONFORM TO
// SPECIFICATIONS, ANY IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR
// A PARTICULAR PURPOSE, OR FREEDOM FROM INFRINGEMENT, ANY WARRANTY THAT
// THE SUBJECT SOFTWARE WILL BE ERROR FREE, OR ANY WARRANTY THAT
// DOCUMENTATION, IF PROVIDED, WILL CONFORM TO THE SUBJECT SOFTWARE.
// 
// __END_LICENSE__

/// \file DiskImageResourceDDD.h
/// 
/// Provides support for Malin Space Science System's DDD image file
/// format.
///
#ifndef __VW_FILEIO_DISK_IMAGE_RESOUCE_DDD_H__
#define __VW_FILEIO_DISK_IMAGE_RESOUCE_DDD_H__

#include <map>
#include <string>
#include <fstream>

#include <vw/Core/Exception.h>
#include <vw/Image/PixelTypes.h>
#include <vw/Image/GenericImageBuffer.h>
#include <vw/FileIO/DiskImageResource.h>

namespace vw
{
  class DiskImageResourceDDD : public DiskImageResource
  {
  public:

    DiskImageResourceDDD(std::string const& filename)
      : DiskImageResource(filename)
    {
      open(filename);
    }
    DiskImageResourceDDD(std::string const& filename, 
			 GenericImageFormat const& format)
      : DiskImageResource(filename)
    {
      create(filename, format);
    }
    virtual ~DiskImageResourceDDD();
    
    virtual void read_generic(GenericImageBuffer const& dest) const;
    virtual void write_generic(GenericImageBuffer const& dest);
    virtual void flush();
    std::string query(std::string const& key) const;
    void open(std::string const& filename);
    void create(std::string const& filename, GenericImageFormat const& format);
    static DiskImageResource* construct_open(std::string const& filename);
    static DiskImageResource* construct_create(std::string const& filename,
					       GenericImageFormat const& format);

  private:

    void parse_ddd_header(const char* label);
    std::string m_filename;
    std::map<std::string, std::string> m_header_entries;
    int m_image_data_offset;
    bool m_is_other_endian;
  };

} // namespace vw

#endif // __VW_FILEIO_DISK_IMAGE_RESOUCE_DDD_H__
