/*
    Carlos Martínez
    https://github.com/carlosEdua
    
    Hangman game in JavaSript with Spanish words
    
    you can change the words in the << PALABRAS >> variable
*/

const IMAGES = [
`     +---+
     |  |
        |
        |
        |
        |
        =========`,
`       +---+
        |   |
        O   |
            |
            |
            |
            =========`,
`       +---+
        |   |
        O   |
        |   |
            |
            |
            =========`,
`       +---+
        |   |
        O   |
       /|   |
            |
            |
            =========`,
`       +---+
        |   |
        O   |
       /|\\  |
            |
            |
            =========`,
`       +---+
        |   |
        O   |
       /|\\  |
        |   |
            |
            =========`,
`       +---+
        |   |
        O   |
       /|\\  |
        |   |
       /    |
            =========`,
`       +---+
        |   |
        O   |
       /|\\  |
        |   | 
       / \\  |
            =========`];

const PALABRAS = [
    'habitacion',
    'internacional',
    'enciclopedia',
    'almohada',
    'continente',
    'especialidad',
    'productividad'
];

function escojerPalabra(){//aqui se escoje una palabra al azar y se regresa
    let index = Math.round(Math.random() * (PALABRAS.length - 1))//su indice
    return PALABRAS[index]
}


function displayBoard(palabraOculta,intentos){
    console.log(IMAGES[intentos]);
    console.log('\n');
    console.log(...palabraOculta);
    console.log('-----------------');
}

function dibujarLetraCorrecta(palabraOculta,letraCorrespondiente,letter,intentos){
    for(let i = 0;i < letraCorrespondiente.length;i++){
        let indice = letraCorrespondiente[i];
        palabraOculta[indice] = letter;
        displayBoard(palabraOculta,intentos)
    }
}


//comprobar si la palabra generada contiene la letra introducida
//y si coincide, meter los indices en un array para luego utilizarlo
//e ir cambiando los caracteres '*__* ' por las letras correctas 
function comprobar(letter,palabraRandom,palabraOculta,intentos){
    letraCorrespondiente = []
    let arrWord = [...palabraRandom];
    for(i = 0; i < palabraRandom.length;i++){
        
        if(arrWord[i].includes(letter)){
            letraCorrespondiente.push(i);
            }
        }
        console.log(letraCorrespondiente);
         
        if (letraCorrespondiente.length == 0){
            return false;
        } else{
            dibujarLetraCorrecta(palabraOculta,letraCorrespondiente,letter,intentos)
            return true;
        }
    }


function empezar(){//
    let palabraRandom = escojerPalabra()
    console.log(palabraRandom);
    
    let palabraOculta = []
    let intentos = 0;
    
    for (let i = 0; i < palabraRandom.length; i++) {
        palabraOculta.push(`*_* `)
        
    }
    // displayBoard(palabraOculta,intentos)//para mostrar los espacios
    
    while(intentos < IMAGES.length -1){
        console.log('estos son los intentos',intentos);
        
        displayBoard(palabraOculta,intentos)
        let currentLetter = prompt('ingresa una letra');
        let comprobado = comprobar(currentLetter,palabraRandom,palabraOculta,intentos)


        if(comprobado){
            let wordHidden = palabraOculta.reduce((a,b) => a + b)
            console.log(wordHidden,palabraRandom);
            
            if(wordHidden == palabraRandom)
            alert('FELICIDADES!! has ganado')
        }
        else{
            intentos++
        }
        console.log('asi va palabra oculta',palabraOculta);

    }
}

empezar()

            