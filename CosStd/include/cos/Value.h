#ifndef COS_VALUE_H
#define COS_VALUE_H

/*
 o---------------------------------------------------------------------o
 |
 | COS Value
 |
 o---------------------------------------------------------------------o
 |
 | C Object System
 |
 | Copyright (c) 2006+ Laurent Deniau, laurent.deniau@cern.ch
 |
 | For more information, see:
 | http://cern.ch/laurent.deniau/cos.html
 |
 o---------------------------------------------------------------------o
 |
 | This file is part of the C Object System framework.
 |
 | The C Object System is free software; you can redistribute it and/or
 | modify it under the terms of the GNU Lesser General Public License
 | as published by the Free Software Foundation; either version 3 of
 | the License, or (at your option) any later version.
 |
 | The C Object System is distributed in the hope that it will be
 | useful, but WITHOUT ANY WARRANTY; without even the implied warranty
 | of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 |
 | See <http://www.gnu.org/licenses> for more details.
 |
 o---------------------------------------------------------------------o
 |
 | $Id: Value.h,v 1.7 2009/02/10 13:03:22 ldeniau Exp $
 |
*/

#ifndef COS_OBJECT_H
#include <cos/Object.h>
#endif 

/* NOTE-USER: Values subclasses

<- Value
   <- Number
      <- Integral
         <- Int
            <- Char
            <- Short
         <- Long
         <- BigInt     (gmp)
      <- Floating
         <- Float
         <- Complex
         <- BigFloat   (gmp)

   <- Range  (1-5 dim)
   <- Slice  (1-5 dim)
*/

defclass(Value)
endclass

#endif // COS_VALUE_H

