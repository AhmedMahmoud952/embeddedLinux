import requests
import pprint
response1 = requests.get('https://api.ipify.org/?format=json')

if response1.status_code == 200:
    ip = response1.json()['ip']
    response2 = requests.get(f'https://ipinfo.io/{ip}/geo')
    if response2.status_code == 200:
        pprint.pprint(response2.json())
    else:
        print("Geo finder failed")
else:
    print("IP finder failed")

