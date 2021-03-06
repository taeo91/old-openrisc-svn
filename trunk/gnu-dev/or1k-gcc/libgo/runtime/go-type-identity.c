/* go-type-identity.c -- hash and equality identity functions.

   Copyright 2009 The Go Authors. All rights reserved.
   Use of this source code is governed by a BSD-style
   license that can be found in the LICENSE file.  */

#include <stddef.h>

#include "go-type.h"

/* The 64-bit type.  */

typedef unsigned int DItype __attribute__ ((mode (DI)));

/* An identity hash function for a type.  This is used for types where
   we can simply use the type value itself as a hash code.  This is
   true of, e.g., integers and pointers.  */

uintptr_t
__go_type_hash_identity (const void *key, uintptr_t key_size)
{
  uintptr_t ret;
  uintptr_t i;
  const unsigned char *p;

  if (key_size <= 8)
    {
      union
      {
	DItype v;
	unsigned char a[8];
      } u;
      u.v = 0;
      __builtin_memcpy (&u.a, key, key_size);
      if (sizeof (uintptr_t) >= 8)
	return (uintptr_t) u.v;
      else
	return (uintptr_t) ((u.v >> 32) ^ (u.v & 0xffffffff));
    }

  ret = 5381;
  for (i = 0, p = (const unsigned char *) key; i < key_size; i++, p++)
    ret = ret * 33 + *p;
  return ret;
}

/* An identity equality function for a type.  This is used for types
   where we can check for equality by checking that the values have
   the same bits.  */

_Bool
__go_type_equal_identity (const void *k1, const void *k2, uintptr_t key_size)
{
  return __builtin_memcmp (k1, k2, key_size) == 0;
}
