from nltk.tokenize import sent_tokenize, word_tokenize
import nltk
nltk.download('punkt')
example_string = """
Sudeep learned rapidly because his first training was in how to learn.
And the first lesson of all was the basic trust that he could learn.
It's shocking to find how many people do not believe they can learn,
and how many more believe learning to be difficult."""

sent_tokenize(example_string)
tokens = word_tokenize(example_string)
print(tokens)
