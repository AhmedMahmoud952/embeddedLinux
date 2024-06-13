import webbrowser
websites = {
    'facebook'  : '"https://web.facebook.com/"',
    'pinterest' : '"https://www.pinterest.com/"',
    'tiktok'    : '"https://www.tiktok.com/"',
    'instagram' : '"https://www.instagram.com/"'
}

# this function return 1 if the value is wrong. if you wanna make a loop in the main code
def openWebsite():
    websiteName = input(f"Enter the desired website of choice from {websites.keys()} \nAsnwer: ")
    if websites.get(websiteName.lower()) != None:
        webbrowser.open_new(websites[websiteName.lower()])
    else:
        print("Wrong Value\n")
        return 1
