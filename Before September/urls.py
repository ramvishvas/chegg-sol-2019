start_urls = []

for year in range(2015, 2019):
        for mongth in range(1, 13):
            start_urls.append('https://www.timeanddate.com/weather/india/sitamarhi/historic?month={}&year={}'.format(mongth, year))

for url in start_urls:
	print(url)