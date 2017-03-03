//===-- MemoryRegionInfo.h ---------------------------------------*- C++
//-*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef lldb_MemoryRegionInfo_h
#define lldb_MemoryRegionInfo_h

#include "lldb/Core/ConstString.h"
#include "lldb/Core/RangeMap.h"
#include "lldb/Utility/Range.h"

namespace lldb_private {
class MemoryRegionInfo {
public:
  typedef Range<lldb::addr_t, lldb::addr_t> RangeType;

  enum OptionalBool { eDontKnow = -1, eNo = 0, eYes = 1 };

  MemoryRegionInfo()
      : m_range(), m_read(eDontKnow), m_write(eDontKnow), m_execute(eDontKnow),
        m_mapped(eDontKnow) {}

  ~MemoryRegionInfo() {}

  RangeType &GetRange() { return m_range; }

  void Clear() {
    m_range.Clear();
    m_read = m_write = m_execute = eDontKnow;
  }

  const RangeType &GetRange() const { return m_range; }

  OptionalBool GetReadable() const { return m_read; }

  OptionalBool GetWritable() const { return m_write; }

  OptionalBool GetExecutable() const { return m_execute; }

  OptionalBool GetMapped() const { return m_mapped; }

  const ConstString &GetName() const { return m_name; }

  void SetReadable(OptionalBool val) { m_read = val; }

  void SetWritable(OptionalBool val) { m_write = val; }

  void SetExecutable(OptionalBool val) { m_execute = val; }

  void SetMapped(OptionalBool val) { m_mapped = val; }

  void SetName(const char *name) { m_name = ConstString(name); }

  //----------------------------------------------------------------------
  // Get permissions as a uint32_t that is a mask of one or more bits from
  // the lldb::Permissions
  //----------------------------------------------------------------------
  uint32_t GetLLDBPermissions() const {
    uint32_t permissions = 0;
    if (m_read)
      permissions |= lldb::ePermissionsReadable;
    if (m_write)
      permissions |= lldb::ePermissionsWritable;
    if (m_execute)
      permissions |= lldb::ePermissionsExecutable;
    return permissions;
  }

  //----------------------------------------------------------------------
  // Set permissions from a uint32_t that contains one or more bits from
  // the lldb::Permissions
  //----------------------------------------------------------------------
  void SetLLDBPermissions(uint32_t permissions) {
    m_read = (permissions & lldb::ePermissionsReadable) ? eYes : eNo;
    m_write = (permissions & lldb::ePermissionsWritable) ? eYes : eNo;
    m_execute = (permissions & lldb::ePermissionsExecutable) ? eYes : eNo;
  }

  bool operator==(const MemoryRegionInfo &rhs) const {
    return m_range == rhs.m_range && m_read == rhs.m_read &&
           m_write == rhs.m_write && m_execute == rhs.m_execute &&
           m_mapped == rhs.m_mapped;
  }

  bool operator!=(const MemoryRegionInfo &rhs) const { return !(*this == rhs); }

protected:
  RangeType m_range;
  OptionalBool m_read;
  OptionalBool m_write;
  OptionalBool m_execute;
  OptionalBool m_mapped;
  ConstString m_name;
};
}

#endif // #ifndef lldb_MemoryRegionInfo_h
