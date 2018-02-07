import requests
from bs4 import BeautifulSoup
import pygsheets
import pandas as pd
import datetime

# natepann today's talk

time = '{:%Y-%m-%d %H:%M:%S}'.format(datetime.datetime.now())

def crw():
    response = requests.get("http://pann.nate.com")
    soup = BeautifulSoup(response.content, "html.parser")
    keywords = soup.select("#container div.today-talk.ellipsis li div > a")
    sh[0].append_table(values=['Timestamp', time])
    for keyword in keywords:
        title = keyword.text
        link = keyword.get("href")
        sh[0].append_table(values=[title, link])


gc = pygsheets.authorize(outh_file='client_secret.json')
sh = gc.open('crw')
sheet1 = sh.sheet1

target = crw()

# csv 파일로 export하기
sheet1.export(pygsheets.ExportType.CSV, filename="sheet1.csv")
