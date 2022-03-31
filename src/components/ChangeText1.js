import React, {useState, useEffect} from 'react';

// import * as myModule from '../cpp/script.js';



export default function ChangeText( props , csvData ) {
    
//     let wasmExports = null;

// let wasmMemory = new WebAssembly.Memory({initial : 256, maximum : 256})

// let wasmTable = new WebAssembly.Table({
//     'initial' : 1,
//     'maximum' : 1,
//     'element' : 'anyfunc'
// });

// let asmLibraryArg = {
//     "__handle_stack_overflow": ()=>{},
//     "emscripten_resize_heap": ()=>{},
//     "__lock": ()=>{},
//     "memory": wasmMemory,
//     "table": wasmTable
// }

// var info = {
//     'env': asmLibraryArg,
//     'wasi_snapshot_preview1': asmLibraryArg,
// };

// async function loadWasm(){
//     let response = await fetch('/cpp/ParsingandChange.wasm');
//     let bytes = await response.arrayBuffer();
//     let wasmObj = await WebAssembly.instantiate(bytes, info);
//     wasmExports = wasmObj.instance.exports;
// }


//     loadWasm();
    console.log("check");
    let dataString;
    let csvFile;

    

    console.log({dataString});

    const[wasm, setWasm] = useState(null);

    useEffect(async () => {
        setWasm(await import("../cpp/ParsingandChange.wasm"));
    }, []);

    // setTimeout(() => { 
    //     csvFile = wasmExports.CsvParsing( csvData );
    //     dataString = wasmExports.ChangeText( props );
    // }, 0);


    return (
    <div>
        {dataString}
    </div>

);

}

