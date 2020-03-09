/*MIT License

Copyright (c) 2018 MTA SZTAKI

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.*/


#ifndef APEHTTPMANAGER_H
#define APEHTTPMANAGER_H

#include <string>
#include "apeILogManager.h"

namespace ape
{
	struct CurlData 
	{
		const char *readptr;
		long sizeleft;
	};

	class HttpManager 
	{
	private:
#ifdef HTTPMANAGER_USE_CURL
		void* mpCurl;
#endif
		
	public:
		HttpManager();
		
		~HttpManager();

		bool downloadResources(const std::string& url, const std::string& location, const std::string& md5 = "");

		std::string download(const std::string& url);
		
		std::string post(const std::string& url, const std::string& data);

		std::string del(const std::string& url, const std::string& data);
	};
}
#endif 
