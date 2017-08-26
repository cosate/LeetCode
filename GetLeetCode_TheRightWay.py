'''
    This time seems to make it though there is still an exception corresponding to question 521.
    I don't know what happened, but to mannually add it. Anyway, it's fucking done.
'''

import urllib.request
import urllib.parse
import urllib.error
import http.cookiejar
import re
import json
import os

user = "gaofeijin"
pwd = "call3180695"
site = "https://leetcode.com/"
site_login = "https://leetcode.com/accounts/login/"
site_submissions_api = "https://leetcode.com/api/submissions/"

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

def writeFile(code, title, num):
    txt = ""
    i = 0
    while i < len(code):
        if code[i] == '\\' and code[i+1] == 'u':
            txt += chr(int(code[i+2:i+6],16))
            i += 6
        else:
            txt += code[i]
            i += 1
    directory = "{0:0>5}".format(num) + " - " + title
    try:
        os.mkdir("./" + directory)
        f = open(directory + r"/" + title + r".cpp",'w')
        f.write(txt)
        f.close()
    except IOError as e:
        pass

def saveCode(pagecode):
    title_begin = re.search(r"<title>",pagecode).span()[1]
    title_end = re.search(r"</title>",pagecode).span()[0]
    title = pagecode[title_begin:title_end - 31]
    
    num_begin = re.search(r"questionId: ",pagecode).span()[1]+1
    num_end = re.search(r"  sessionId:",pagecode).span()[0]-3
    num = pagecode[num_begin:num_end]
    
    code_begin = re.search(r"submissionCode: ",pagecode).span()[1]+1
    code_end = re.search(r"  editCodeUrl:",pagecode).span()[0]-3
    code = pagecode[code_begin:code_end]
    writeFile(code, title, num)
    
def getPage(page):
    try:
        code_url = urlOpener.open(site + page)
    except urllib.error.URLError as u:
        print(u.reason)
    else:
        code_page = code_url.read()
        code_page = code_page.decode()
        saveCode(code_page)

def getAcceptedSubmissions():
    acsub = list()
    for i in range(0,601,20):
        url = site_submissions_api + "?offset=" + str(i) +"&limit=20"
        res = urlOpener.open(url).read().decode()
        jsondata = json.loads(res)
        for j in range(0,len(jsondata["submissions_dump"])):
            if jsondata["submissions_dump"][j]["status_display"] == "Accepted":
                acsub.append(jsondata["submissions_dump"][j]["url"])  
    return acsub
       
if __name__ == '__main__':
    login()
    aclist = getAcceptedSubmissions()
    for lis in aclist:
        getPage(lis)
