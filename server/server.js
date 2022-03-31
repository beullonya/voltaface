// app.get('/:filename.wasm', (req, res) => {
//     const wasmFilePath = path.resolve(__dirname, 
//       `../../dist/${req.params.filename}.wasm`);
    
//     console.log(`Wasm request ${wasmFilePath}`);
  
//     fs.readFile(wasmFilePath, (err, data) => {
//       const errorMessage = `Error ${wasmFilePath} not found. ${JSON.stringify(err)}`;
//       if (err) {
//         console.log(errorMessage);
//         res.status(404).send(errorMessage);
//         return;
//       }
//       res.send(data);
//     });
//   });