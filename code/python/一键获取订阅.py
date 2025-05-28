import requests
import random
from bs4 import BeautifulSoup
import re
# 目标URL
register_url = "https://lightsr.com/auth/register"
session = requests.session()
random_email_str = ''.join([str(random.randint(1, 9)) for _ in range(10)]) + '@qq.com'
# 请求头
headers = {
    "User-Agent": "Mozilla/5.0 (Linux; Android 6.0; Nexus 5 Build/MRA58N) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/132.0.0.0 Mobile Safari/537.36",
    "Referer": "https://lightsr.com/auth/register",
    "Origin": "https://lightsr.com",
}

# 注册表单数据
payload = {
    "name": "yournickname1",  # 替换为你的昵称
    "email": random_email_str,  # 替换为你的邮箱
    "passwd": "cccc1111",  # 替换为你的密码
    "repasswd": "cccc1111",  # 重复密码
    "agree": "on",  # 同意服务条款
}

try:
    # 发送POST请求
    response = session.post(register_url, data=payload, headers=headers).json()

    # 检查注册结果
    if response['ret'] == 1:  # 注册成功
        #  登录
        url1 = 'https://lightsr.com/auth/login'
        url2 = 'https://lightsr.com/user'
        payload.get('name')
        data = {
            'email': payload.get('email'),
            'passwd': payload.get('passwd'),
            'remember_me': 'on',
            'code': ''
        }
        res = session.post(url=url1, headers=headers, data=data)
        print('res', res)
        res2 = session.get(url=url2, headers=headers)
        html_content = res2.content.decode()
        # print('res2:', res2.content.decode())
        soup = BeautifulSoup(html_content, 'html.parser')
        subscription_buttons = soup.find_all('button')
        # 提取链接
        v2ray_subscription_url = None
        clash_subscription_url = None
        for button in subscription_buttons:
            # Check if the button has the data-clipboard-text attribute
            if button.get('data-clipboard-text'):
                if 'V2Ray' in button.text:  # 确认文本中包含“v2ray”
                    v2ray_subscription_url = button['data-clipboard-text']
                    break  # 找到后可以结束循环
                if 'Clash' in button.text:
                    clash_subscription_url = button['data-clipboard-text']


        if v2ray_subscription_url:
            print('V2Ray 订阅链接:', v2ray_subscription_url)
        else:
            print('未找到V2Ray订阅链接')
        if clash_subscription_url:
            print('Clash 订阅链接:', clash_subscription_url)
        else:
            print('未找到Clash订阅链接')

    else:
        print("注册失败:", response['msg'])
except Exception as e:
    print(f'发生错误:{e}')
    
