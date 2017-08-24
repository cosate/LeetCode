import urllib.request
import urllib.parse
import urllib.error
import http.cookiejar
import re

user = "gaofeijin"
pwd = "call3180695"
site_login = "https://leetcode.com/accounts/login/"
site_code = "https://leetcode.com/submissions/detail/"
csrf = ""

cookie = http.cookiejar.MozillaCookieJar()
urlOpener = urllib.request.build_opener(urllib.request.HTTPCookieProcessor(cookie))

urlOpener.open(site_login)
for ck in cookie:
    csrf = ck.value

values = {'csrfmiddlewaretoken':csrf,'login':user,'password':pwd}
values = urllib.parse.urlencode(values)
values = values.encode()
headers = {'User-Agent':'Mozilla/5.0 (Windows NT 10.0; WOW64; rv:55.0) Gecko/20100101 Firefox/55.0','Referer':'https://leetcode.com'}
login_request = urllib.request.Request(site_login,values,headers=headers)
login_url = urlOpener.open(login_request)
login_page = login_url.read()
login_page = login_page.decode()

print(len(login_page))
print(re.search("gaofeijin",login_page))

for i in range(57856709,57856719):
    try:
        code_url = urlOpener.open(site_code + str(i))
    except urllib.error.HTTPError as e:
        print(e.code)
    else:
        code_page = code_url.read()
        code_page = code_page.decode()
        print(re.search("status_code: parseInt",code_page))
