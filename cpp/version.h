// generated by CommonLibrary.cmake, do not edit.

/**
 * @file include/@INCLUDE_NAME@/version.h
 * Defines version macros and class for library @Name@.
 */

#ifndef @NAME@_VERSION_H
#define @NAME@_VERSION_H

#include <@INCLUDE_NAME@/api.h>
#include <string>

namespace @namespace@
{
    /** The current major version. */
#   define @NAMESPACE@_VERSION_MAJOR @VERSION_MAJOR@

    /** The current minor version. */
#   define @NAMESPACE@_VERSION_MINOR @VERSION_MINOR@

    /** The current patch level. */
#   define @NAMESPACE@_VERSION_PATCH @VERSION_PATCH@

    /** The current SCM revision. */
#   define @NAMESPACE@_VERSION_REVISION 0x@GIT_REVISION@

    /** The current binary interface. */
#   define @NAMESPACE@_VERSION_ABI @VERSION_ABI@

/** True if the current version is newer than the given one. */
#   define @NAMESPACE@_VERSION_GT( MAJOR, MINOR, PATCH )       \
    ( (@NAMESPACE@_VERSION_MAJOR>MAJOR) ||                     \
      (@NAMESPACE@_VERSION_MAJOR==MAJOR && (@NAMESPACE@_VERSION_MINOR>MINOR || \
          (@NAMESPACE@_VERSION_MINOR==MINOR && @NAMESPACE@_VERSION_PATCH>PATCH))))

/** True if the current version is equal or newer to the given. */
#   define @NAMESPACE@_VERSION_GE( MAJOR, MINOR, PATCH )       \
    ( (@NAMESPACE@_VERSION_MAJOR>MAJOR) ||                     \
      (@NAMESPACE@_VERSION_MAJOR==MAJOR && (@NAMESPACE@_VERSION_MINOR>MINOR || \
          (@NAMESPACE@_VERSION_MINOR==MINOR && @NAMESPACE@_VERSION_PATCH>=PATCH))))

/** True if the current version is older than the given one. */
#   define @NAMESPACE@_VERSION_LT( MAJOR, MINOR, PATCH )       \
    ( (@NAMESPACE@_VERSION_MAJOR<MAJOR) ||                     \
      (@NAMESPACE@_VERSION_MAJOR==MAJOR && (@NAMESPACE@_VERSION_MINOR<MINOR || \
          (@NAMESPACE@_VERSION_MINOR==MINOR && @NAMESPACE@_VERSION_PATCH<PATCH))))

/** True if the current version is older or equal to the given. */
#   define @NAMESPACE@_VERSION_LE( MAJOR, MINOR, PATCH )       \
    ( (@NAMESPACE@_VERSION_MAJOR<MAJOR) ||                     \
      (@NAMESPACE@_VERSION_MAJOR==MAJOR && (@NAMESPACE@_VERSION_MINOR<MINOR || \
        (@NAMESPACE@_VERSION_MINOR==MINOR && @NAMESPACE@_VERSION_PATCH<=PATCH))))

/** Information about the current @Name@ version. */
class @NAMESPACE@_API Version
{
public:
    /** @return the current major version of @Name@. */
    static int getMajor();

    /** @return the current minor version of @Name@. */
    static int getMinor();

    /** @return the current patch level of @Name@. */
    static int getPatch();

    /** @return the current @Name@ version (MM.mm.pp). */
    static std::string getString();

    /** @return the SCM revision. */
    static int getRevision();

    /** @return the current binary interface version of @Name@. */
    static int getABI();

    /** @return the current @Name@ version plus the git SHA hash (MM.mm.pp.rev). */
    static std::string getRevString();

    /**
     * Runtime check for ABI compatibility.
     *
     * Call from code using @Name@. Will fail if the executable
     * was compiled against a version incompatible with the runtime version.
     *
     * @return true if the link-time and compile-time DSO are compatible.
     */
    static bool check()
    {
        return getMajor()==@NAMESPACE@_VERSION_MAJOR &&
               getMinor()==@NAMESPACE@_VERSION_MINOR;
    }
};

}

#endif
