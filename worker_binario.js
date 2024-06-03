self.onmessage = function run_Binario(e){
    console.log(e.data.cmd)
    WebAssembly.instantiateStreaming(
        fetch("buscar.wasm"),
        {}
    ).then(result => {
       

        var resultado_Binario = result.instance.exports.Binario(e.data.cmd);
        
        console.log(resultado_Binario);

        self.postMessage({cmd: resultado_Binario})
        
    })
}