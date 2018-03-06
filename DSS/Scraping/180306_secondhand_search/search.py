import requests
import pandas as pd
from bs4 import BeautifulSoup
import pickle

# 전체 데이터 갯수를 가져오는 함수
def get_total(keyword):
    response = requests.get("https://m.cafe.naver.com/ArticleSearchList.nhn?search.query={}\
                            &search.menuid=&search.searchBy=1&search.sortBy=date&search.clubid=10050146&search.option=0&search.defaultValue=".format(keyword))
    soup = BeautifulSoup(response.content, "html.parser")
    return soup.select_one("#ct > div.search_contents > div.search_sort > div.sort_l > span").text

# 아이템 리스트를 가져오는 함수
def get_items(keyword, page):
    response = requests.get("https://m.cafe.naver.com/ArticleSearchListAjax.nhn?search.query={}\
                            &search.menuid=&search.searchBy=1&search.sortBy=date&search.clubid=10050146&search.option=0&search.defaultValue=&search.page={}".format(keyword, page))
    soup = BeautifulSoup(response.content, "html.parser")
    return soup.select('ul li')


# 상세 페이지에서 가격정보를 가져오는 함수
def get_price(link):
    with open('cookie.bin', 'rb') as f:
        a = pickle.load(f) # when you use pickle, never ever name that file as pickle.py like that
    headers = {
            "cookie" : "{}".format(a),
            "user-agent" : 'Mozilla/5.0 (compatible; MSIE 9.0; Windows NT 6.0; Trident/4.0; GTB7.4; InfoPath.3; SV1; .NET CLR 3.1.76908; WOW64; en-US)'
        }
    f.close()
    response = requests.get(link, headers=headers)
    soup = BeautifulSoup(response.content, "html.parser")
    return soup.select_one('.price em').text

# 아이템을 데이터 리스트로 만드는 함수
def make_datas(items):
    datas = []

    for item in items:
        #판매중인지 체크
        try:
            sell = item.select_one(".icon_txt").text
            if sell == "완료":
                continue
        except:
            continue

        title = item.select_one("h3").text
        link = "https://m.cafe.naver.com/{}".format(item.select_one("a").attrs["href"])
        view = item.select_one(".no em").text
        date = item.select_one(".time").text
        price = get_price(link)

        datas.append([title, view, date, price, link])
    print(len(datas))
    return datas

# 키워드를 입력받아 전체 데이터를 가져오는 함수
def all_datas(keyword):
    datas=[]
    a = int(get_total(keyword))
    total = a//20 + 1
    for i in range(1, total+1):
        item = get_items(keyword, i)
        datas.extend(make_datas(item))
    return datas

# 데이터 프레임화 + csv파일로 저장
datas = all_datas("공기측정기")

columns = ["title", "views", "date", "price", "link"]

df = pd.DataFrame(datas, columns=columns)
df.to_csv("PeacefulWorld.csv")
