Step 1: Import Required Libraries
from nltk.corpus import stopwords
import string
# Download required resources
nltk.download('punkt')
nltk.download('punkt_tab')
nltk.download('stopwords')


Step 2: Define Text and Perform Tokenization
# Input text
a = input("Enter a text:")
# Tokenization
tokens = word_tokenize(a)
print("Tokens:", tokens)

OUTPUT :
Enter a text:Wow! Such a beautiful morning
Tokens: ['Wow', '!', 'Such', 'a', 'beautiful', 'morning']

Step 3: Remove Stopwords and Punctuations
#Define stopwords and punctuations
stop_words = set(stopwords.words('english'))
punctuations = set(string.punctuation)
#Filter out stopwords and punctuations
filtered_tokens = []
for word in tokens:
if word.lower() not in stop_words and word not in string.punctuation:
filtered_tokens.append (word)
print("Filtered Tokens:", filtered_tokens)


OUTPUT:
Enter a text:Wow! Such a beautiful morning.
Tokens: ['Wow', '!', 'Such', 'a', 'beautiful', 'morning', '.']
Filtered Tokens: ['Wow', 'beautiful', 'morning'[