import nltk
nltk.download('averaged_perceptron_tagger')

from nltk.tokenize import word_tokenize
sagan_quote = """
If you wish to make an apple pie from scratch,
you must first invent the universe."""

words_in_sagan_quote = word_tokenize(sagan_quote)
pos = nltk.pos_tag(words_in_sagan_quote)

print(pos)
grammar = "NP: {<DT>?<JJ>*<NN>}"
chunk_parse = nltk.RegexpParser(grammar)
tree = chunk_parse.parse(pos)
tree.draw()

# top down parse