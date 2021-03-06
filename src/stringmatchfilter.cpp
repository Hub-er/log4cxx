/***************************************************************************
              stringmatchfilter.cpp  -  class StringMatchFilter
                             -------------------
    begin                : dim mai 18 2003
    copyright            : (C) 2003 by Michael CATANZARITI
    email                : mcatan@free.fr
 ***************************************************************************/

/***************************************************************************
 * Copyright (C) The Apache Software Foundation. All rights reserved.      *
 *                                                                         *
 * This software is published under the terms of the Apache Software       *
 * License version 1.1, a copy of which has been included with this        *
 * distribution in the LICENSE.txt file.                                   *
 ***************************************************************************/

#include <log4cxx/varia/stringmatchfilter.h>
#include <log4cxx/spi/loggingevent.h>
#include <log4cxx/helpers/stringhelper.h>
#include <log4cxx/helpers/optionconverter.h>

using namespace log4cxx::varia;
using namespace log4cxx::spi;
using namespace log4cxx::helpers;

tstring StringMatchFilter::STRING_TO_MATCH_OPTION = _T("StringToMatch");
tstring StringMatchFilter::ACCEPT_ON_MATCH_OPTION = _T("AcceptOnMatch");

StringMatchFilter::StringMatchFilter() : acceptOnMatch(true)
{
}

void StringMatchFilter::setOption(const std::string& option,
	const std::string& value)
{
	if (StringHelper::equalsIgnoreCase(option, STRING_TO_MATCH_OPTION))
	{
		stringToMatch = value;
	}
	else if (StringHelper::equalsIgnoreCase(option, ACCEPT_ON_MATCH_OPTION))
	{
		acceptOnMatch = OptionConverter::toBoolean(value, acceptOnMatch);
	}
}

int StringMatchFilter::decide(const log4cxx::spi::LoggingEvent& event)
{
	const tstring& msg = event.getRenderedMessage();

	if(msg.empty() || stringToMatch.empty())
	{
		return Filter::NEUTRAL;
	}


	if( msg.find(stringToMatch) == tstring::npos )
	{
		return Filter::NEUTRAL;
	}
	else
	{ // we've got a match
		if(acceptOnMatch)
		{
			return Filter::ACCEPT;
		}
		else
		{
			return Filter::DENY;
		}
	}
}

