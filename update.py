'''
coding:UTF-8
files:ANSI

Code with Pycharm Python 3.11.4

author: Rabbit max、魏子芮、Sean537
audit：Sean537

Copyright©537 Studio.2023-2024.All rights reserved.
'''
import requests
import os

# 要保存的网页URL
url = 'https://www.537studio.com/software/update/537Toolbox_NewVersion.txt'

# 发送HTTP请求获取网页内容
response = requests.get(url)

# 确保请求成功
if response.status_code == 200:
    # 定义保存文件的路径为当前目录下的temp文件夹
    # 如果temp文件夹不存在，os.path.join和随后的文件操作会自动创建它
    file_path = os.path.join('temp', 'new_version.txt')

    # 打开一个文件以写入模式，并使用ANSI编码（Windows-1252）
    with open(file_path, 'w', encoding='ANSI') as file:
        # 将网页内容写入文件
        file.write(response.text)
else:
    #请求失败
    file_path = os.path.join('temp', 'new_version.txt')
    with open(file_path, 'w', encoding='ANSI') as file:
        file.write('0')