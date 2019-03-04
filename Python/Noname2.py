from wordcloud import wordcloud
import plt.image as image
with open ("f:\a.txt") as fp:
	text = fp.read()

wordcloud = wordcloud().generate(text)
image_produce = wordcloud.to_image()
image_produce.show()