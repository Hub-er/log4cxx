/*
 * Copyright 2003,2004 The Apache Software Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _LOG4CXX_HELPERS_INTEGER_H
#define _LOG4CXX_HELPERS_INTEGER_H

#include <log4cxx/helpers/objectimpl.h>


namespace log4cxx {
   namespace helpers {
      class Integer : public virtual ObjectImpl {
          const int val;
      public:
      DECLARE_LOG4CXX_OBJECT(Integer)
      BEGIN_LOG4CXX_CAST_MAP()
              LOG4CXX_CAST_ENTRY(Integer)
      END_LOG4CXX_CAST_MAP()

      Integer();
      Integer(int i);
      virtual ~Integer();

      inline int intValue() const {
        return val;
      }

      };

      typedef log4cxx::helpers::ObjectPtrT<Integer> IntegerPtr;

   }
};


#endif