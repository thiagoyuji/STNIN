import spacy
en_nlp = spacy.load('en')
en_doc = en_nlp(u'Hello, world. Here are two sentences.')