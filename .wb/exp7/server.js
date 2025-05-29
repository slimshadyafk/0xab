import express from "express";

const app = express();
app.use(express.json());

app.use((req, res, next)=>{
	console.log(
		req.url
	)
	next();
})

const products = [];

app.get("/", (req, res) => {
  res.json({ success: true, message: "Hello" });
});
app.get("/products/", (req, res) => {
	res.json({success: true, products});
});
app.get("/products/:id", (req, res) => {
  const id = req.params.id;
  const data = products.filter((el) => el.id == id);
  if (data.length !== 0) {
    return res.json({ success: true, data });
  }
  res.json({ success: false, error: `No Product with id: ${id}` });
});

app.post("/products", (req, res) => {
  const { id, name } = req.body;
  const newProduct = { id, name };
  products.push(newProduct);
  res.send(newProduct);
});

app.put("/products/:id", (req, res) => {
  const product = products.find((item) => item.id.toString() === req.params.id);
  Object.assign(product, req.body);
  res.send(product);
});

app.delete("/products/:id", (req, res) => {
  const index = products.findIndex(
    (item) => item.id.toString() === req.params.id
  );
  const deletedProduct = products.splice(index, 1);
  res.send(deletedProduct);
});

app.listen(3000, () => {
  console.log("Server running on http://localhost:3000");
});
