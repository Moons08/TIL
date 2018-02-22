from selenium import webdriver
import pandas as pd

df = pd.DataFrame(columns=["rank", "team", "played", "won", "drawn", "lost"])

def crw():

    driver = webdriver.Chrome()
    driver.get('https://www.premierleague.com/tables')
    driver.find_element_by_css_selector('#advertClose').click() # pop-up close
    items = driver.find_elements_by_css_selector(".allTablesContainer table > \
                                                 tbody > tr:not(.expandable)")

    for idx, item in enumerate(items):

        rank = item.find_element_by_css_selector("td > .value")
        team = item.find_element_by_css_selector(".team .long")
        played = item.find_element_by_css_selector("td:nth-child(4)")
        won = item.find_element_by_css_selector("td:nth-child(5)")
        drawn = item.find_element_by_css_selector("td:nth-child(6)")
        lost = item.find_element_by_css_selector("td:nth-child(7)")

        data = {"rank" : rank.text,
                "team" : team.text,
                "played" : played.text,
                "won": won.text,
                "drawn":drawn.text,
                "lost":lost.text,
        }
        df.loc[len(df)] = data

        if idx == 19:
            break;

    driver.close()
    df.to_csv("premier_table.csv", encoding="utf-8")

crw()
