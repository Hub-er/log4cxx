/*
 * Copyright 2003-2005 The Apache Software Foundation.
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

#include <log4cxx/ttcclayout.h>
#include <log4cxx/spi/loggingevent.h>
#include <log4cxx/level.h>
#include <log4cxx/helpers/stringhelper.h>
#include <log4cxx/ndc.h>

using namespace log4cxx;
using namespace log4cxx::spi;
using namespace log4cxx::helpers;

IMPLEMENT_LOG4CXX_OBJECT(TTCCLayout)

TTCCLayout::TTCCLayout()
: DateLayout(LOG4CXX_STR("RELATIVE")), threadPrinting(true), categoryPrefixing(true),
contextPrinting(true), filePrinting(false)
{
        Pool pool;
        activateOptions(pool);
}

TTCCLayout::TTCCLayout(const LogString& dateFormatType)
: DateLayout(dateFormatType), threadPrinting(true), categoryPrefixing(true),
contextPrinting(true), filePrinting(false)
{
        Pool pool;
        activateOptions(pool);
}

void TTCCLayout::format(LogString& output,
      const spi::LoggingEventPtr& event,
      Pool& p) const
{
        formatDate(output, event, p);

        if(threadPrinting)
        {
                output.append(1, LOG4CXX_STR('['));
                output.append(event->getThreadName());
                output.append(LOG4CXX_STR("] "));
        }

        output.append(event->getLevel()->toString());
        output.append(1, LOG4CXX_STR(' '));
        if(categoryPrefixing)
        {
                output.append(event->getLoggerName());
                output.append(1, LOG4CXX_STR(' '));
        }

        if(contextPrinting)
        {
                LogString ndc = event->getNDC();

                if(!NDC::isNull(ndc))
                {
                        output.append(ndc);
                        output.append(1, LOG4CXX_STR(' '));
                }
        }

        output.append(LOG4CXX_STR("- "));
        output.append(event->getRenderedMessage());
        output.append(LOG4CXX_EOL);
}
