import requests
from bs4 import BeautifulSoup
import pygsheets
import pandas as pd
import datetime

# biz.chosun top news

time = '{:%Y-%m-%d %H:%M:%S}'.format(datetime.datetime.now())

def crw():
    response = requests.get("http://biz.chosun.com")
    soup = BeautifulSoup(response.content, "html.parser")
    keywords = soup.select(".hd_ul2 > li")
    sh[0].append_table(values=['Timestamp', time])
    for keyword in keywords:
        title = keyword.select_one("a").text
        auth = keyword.select_one(".art_auth").text
        sh[0].append_table(values=[title, auth])

gc = pygsheets.authorize(outh_file='client_secret.json')
sh = gc.open('crw')
sheet1 = sh.sheet1

target = crw()

# csv 파일로 export하기
sheet1.export(pygsheets.ExportType.CSV, filename="sheet1.csv")
