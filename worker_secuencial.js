self.onmessage = function run_secuencial(e){
    console.log(e.data.cmd)
    WebAssembly.instantiateStreaming(
        fetch("buscar.wasm"),
        {}
    ).then(result => {
       

        var resultado_Secuencial = result.instance.exports.Secuencial(e.data.cmd);
        
        console.log(resultado_Secuencial);

        self.postMessage({cmd: resultado_Secuencial})
        
    })
}