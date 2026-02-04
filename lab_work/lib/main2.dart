import 'package:flutter/material.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  // This widget is the root of your application.
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Flutter Demo',
      theme: ThemeData(
        colorScheme: .fromSeed(seedColor: Colors.deepPurple),
      ),
      home: const MyHomePage(title: 'Flutter Demo Home Page'),
    );
  }
}

class MyHomePage extends StatefulWidget {
  const MyHomePage({super.key, required this.title});

  final String title;

  @override
  State<MyHomePage> createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyHomePage> {
  bool _isPasswordObscure = true;

  final _userId = TextEditingController(),
        _password = TextEditingController();

  bool _isUserIdEmpty = false;
  bool _isPasswordEmpty = false;

  void validate() {
    // if (_userId.text.isEmpty) {
    //   ScaffoldMessenger.of(context).showSnackBar(
    //       SnackBar(
    //         backgroundColor: Color.fromRGBO(255, 0, 0, 1),
    //           content: Center(child: Text('Please Enter User ID'))
    //       )
    //   );
    // }
    //
    // if (_password.text.isEmpty) {
    //   ScaffoldMessenger.of(context).showSnackBar(
    //       SnackBar(
    //           backgroundColor: Color.fromRGBO(255, 255, 0, 1),
    //           content: Center(child: Text('Please Enter Password'))
    //       )
    //   );
    // }

    setState(() {
      _isUserIdEmpty = _userId.text.isEmpty;
      _isPasswordEmpty = _password.text.isEmpty;
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        backgroundColor: Theme.of(context).colorScheme.inversePrimary,
        title: Text(widget.title),
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: .center,
          children: [
            Padding(
              padding: const EdgeInsets.all(8.0),
              child: TextField(
                controller: _userId,
                onChanged: (value){
                  setState(() {
                    _isUserIdEmpty = value.isEmpty;
                  });
                },
                decoration: InputDecoration(
                  errorText: _isUserIdEmpty ? 'Please Enter User ID' : null,
                  border: OutlineInputBorder(
                    borderRadius: BorderRadius.circular(10.0),
                  ),
                  labelText: 'User ID',
                  hintText: 'Type email abc@gmail.com'
                ),
              ),
            ),
            Padding(
              padding: const EdgeInsets.all(8.0),
              child: TextField(
                obscureText: _isPasswordObscure,
                controller: _password,
                onChanged: (value){
                  setState(() {
                    _isPasswordEmpty = value.isEmpty;
                  });
                },
                decoration: InputDecoration(
                  errorText: _isPasswordEmpty ? 'Please Enter Password' : null,
                  suffixIcon: IconButton(
                      onPressed: (){
                        setState(() {
                          _isPasswordObscure = !_isPasswordObscure;
                        });
                      },
                      icon: Icon(Icons.remove_red_eye)
                  ),
                  border: OutlineInputBorder(
                    borderRadius: BorderRadius.circular(10.0),
                  ),
                  labelText: 'Password',
                  hintText: 'Enter Password'
                ),
              ),
            ),
            ElevatedButton(onPressed: validate, child: Text('Login')),
          ],
        ),
      ),
    );
  }
}

//Regular Expression (Regex): regexr.com