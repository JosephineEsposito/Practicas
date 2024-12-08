// Project14.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

///
/// [ ] ¿Cuánto espacio ocupa la tabla de funciones virtuales?
/// [ ] ¿Dónde está situada la tabla de funciones virtuales ?
/// [ ] ¿Cuánto espacio ocupa adicionalmente un objeto por tener una tabla de funciones virtuales ?
/// [ ] ¿Qué pasa si llamo a un método virtual desde el constructor ?
/// [ ] Comparar la llamada a una función virtual con la llamada a una función no virtual.¿Cuántos pasos adicionales tienen que realizarse para llamar a una función cuando esta es virtual ?
///


#include <iostream>





class B
{
public:
  virtual void bar();
  virtual void qux();
};

void B::bar()
{
  std::cout << "This is B's implementation of bar" << std::endl;
}

void B::qux()
{
  std::cout << "This is B's implementation of qux" << std::endl;
}

class C : public B
{
public:
  void* point;
  void bar() override;
};

void C::bar()
{
  std::cout << "This is C's implementation of bar" << std::endl;
}


class A : public B
{
public:
  A();
};

A::A()
{
  bar();
}

int main()
{
  B* b = new C();
  b->bar();


  std::cout << "1.Cuanto espacio ocupa la tabla de funciones virtuales?\n";
  std::cout << "|\tLa tabla de funciones virtuales ocupa el espacio de un puntador por cada funcion virtual que almacena\n";
  std::cout << "|\tSi un puntador vale 4, entonces la clase B valdría 8 al tener dos funciones virtuales\n";
  std::cout << "|\tsizeof(B) : " << sizeof(B) << "\n";

  std::cout << "\n\n";


  std::cout << "2.Donde esta situada la tabla de funciones virtuales?\n";
  std::cout << "|\tLa tabla de funciones virtuales se almacena en el heap igual que las variables de tipo static\n";

  std::cout << "\n\n";

  std::cout << "3.Cuanto espacio ocupa adicionalmente un objeto por tener una tabla de funciones virtuales?" << "\n";
  std::cout << "|\tUn objeto ocupa adicionalmente 4 bytes por virtual method\n";
  std::cout << "|\tLa clase C tiene una variable puntero de tipo void* de tamaño: " << sizeof(void*) << "\n";
  std::cout << "|\tMientras que su tamaño por entero es de: " << sizeof(C) << "\n";

  std::cout << "\n\n";

  std::cout << "4.Que pasa si llamo a un método virtual desde el constructor?" << "\n";
  std::cout << "|\tEn la clase A llamamos el metodo virtual bar() en su constructor, el resultado es:\n";
  std::cout << "|\t";
  A* a = new A();
  std::cout << "|\tSi no especificamos en la declaracion de la clase, el override del metodo virtual, se manda a llamar el del padre\n";

  std::cout << "\n\n";

  std::cout << "5.Cuantos pasos adicionalmente tienen que realizarse para llamar a una función cuando esta es virtual?" << "\n";
  std::cout << "|\tDependiendo de su implementacion pueden aumentar los pasos de ejecucion. Por ejemplo, mientras que con un override se manda a llamar directamente el metodo virtual de la clase actual (o hija);\n";
  std::cout << "|\tsin un override, se manda a llamar el metodo virtual \"original\", es decir, el del padre. El metodo virtual del padre es el que se va a guardar como primer elemento en la tabla virutal.\n";
}
//EOF
