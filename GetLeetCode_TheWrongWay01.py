'''
    This is the brutal way to get the AC code from leetcode. And as it should be, the server has
    fobided booming access. Anyway, mission failed, once.
'''

import urllib.request
import urllib.parse
import urllib.error
import http.cookiejar
import re
import threading
import threadpool
import time

user = "gaofeijin"
pwd = "call3180695"
site_login = "https://leetcode.com/accounts/login/"
site_code = "https://leetcode.com/submissions/detail/"

cookie = http.cookiejar.MozillaCookieJar()
urlOpener = urllib.request.build_opener(urllib.request.HTTPCookieProcessor(cookie))

def login():
    urlOpener.open(site_login)
    for ck in cookie:
        csrf = ck.value
    values = {'csrfmiddlewaretoken':csrf,'login':user,'password':pwd}
    values = urllib.parse.urlencode(values)
    values = values.encode()
    headers = {'User-Agent':'Mozilla/5.0 (Windows NT 10.0; WOW64; rv:55.0) Gecko/20100101 Firefox/55.0','Referer':'https://leetcode.com'}
    login_request = urllib.request.Request(site_login,values,headers=headers)
    login_url = urlOpener.open(login_request)
    
def getpage(page):
    try:
        code_url = urlOpener.open(site_code + str(page))
    except urllib.error.HTTPError as e:
        pass
    except urllib.error.URLError as u:
        print(page)
    else:
        code_page = code_url.read()
        code_page = code_page.decode()
        print(re.search("status_code: parseInt",code_page))
        
if __name__ == '__main__':
    login()
    threads = list()
    for i in range(57856709,57866709):
        threads.append(threading.Thread(target = getpage, args = (i,)))

    for i in range(0,10000):
        threads[i].start()

    for i in range(0,10000):
        threads[i].join()
