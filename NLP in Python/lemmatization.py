import nltk
nltk.download('wordnet')
from nltk.stem import WordNetLemmatizer
lemmatizer = WordNetLemmatizer()
from nltk.tokenize import word_tokenize
string_for_lemmatizing = "The friends of mine love scarves."
words = word_tokenize(string_for_lemmatizing)
lemmatized_words = [lemmatizer.lemmatize(word) for word in words]
# print(lemmatized_words)

wors = lemmatizer.lemmatize("worst", pos="a")
print(wors)