
type account = {
login: string,
currency: string
};

type category = {
id: string,
name: string,
url: string,
image: string,
description: string
};

type product = {
id: string,
name: string,
price: string,
url: string,
image: string,
description: string
};

type item = {
id: string,
name: string
}

type review = {
id: string,
name: string
}

type reviews = list(review)

type menu = list(item)

type categories = option(list(category))
type categories_list = list(category)

type products = option(list(product))

type products_list = list(product)

type cart = products