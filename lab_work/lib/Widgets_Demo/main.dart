import 'package:flutter/material.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Lab 2: Flutter Widgets & Project Structure',
      theme: ThemeData(
        colorScheme: ColorScheme.fromSeed(seedColor: Colors.deepPurple),
        useMaterial3: true,
      ),
      home: const WidgetsDemoPage(),
    );
  }
}

class WidgetsDemoPage extends StatelessWidget {
  const WidgetsDemoPage({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Lab 2: Flutter Widgets Demo'),
        centerTitle: true,
      ),
      body: ListView(
        padding: const EdgeInsets.all(16),
        children: [
          // Text Widget
          const SizedBox(height: 16),
          const Text(
            'Text Widget Example',
            style: TextStyle(
              fontSize: 24,
              fontWeight: FontWeight.bold,
              color: Colors.deepPurple,
            ),
          ),
          const SizedBox(height: 8),
          const Text(
            'This is a basic Text widget displaying content',
            style: TextStyle(fontSize: 16, color: Colors.grey),
          ),

          // Container Widget
          const SizedBox(height: 24),
          const Text(
            'Container Widget Example',
            style: TextStyle(
              fontSize: 24,
              fontWeight: FontWeight.bold,
              color: Colors.deepPurple,
            ),
          ),
          const SizedBox(height: 8),
          Container(
            padding: const EdgeInsets.all(16),
            decoration: BoxDecoration(
              color: Colors.deepPurple.shade100,
              borderRadius: BorderRadius.circular(12),
              border: Border.all(color: Colors.deepPurple, width: 2),
            ),
            child: const Text(
              'This is a Container with custom styling, padding, and border',
              style: TextStyle(fontSize: 16, color: Colors.deepPurple),
            ),
          ),

          // Row Widget
          const SizedBox(height: 24),
          const Text(
            'Row Widget Example',
            style: TextStyle(
              fontSize: 24,
              fontWeight: FontWeight.bold,
              color: Colors.deepPurple,
            ),
          ),
          const SizedBox(height: 8),
          Row(
            mainAxisAlignment: MainAxisAlignment.spaceEvenly,
            children: [
              Container(
                padding: const EdgeInsets.all(12),
                color: Colors.blue,
                child: const Text('Item 1', style: TextStyle(color: Colors.white)),
              ),
              Container(
                padding: const EdgeInsets.all(12),
                color: Colors.green,
                child: const Text('Item 2', style: TextStyle(color: Colors.white)),
              ),
              Container(
                padding: const EdgeInsets.all(12),
                color: Colors.orange,
                child: const Text('Item 3', style: TextStyle(color: Colors.white)),
              ),
            ],
          ),

          // Column Widget
          const SizedBox(height: 24),
          const Text(
            'Column Widget Example',
            style: TextStyle(
              fontSize: 24,
              fontWeight: FontWeight.bold,
              color: Colors.deepPurple,
            ),
          ),
          const SizedBox(height: 8),
          Column(
            crossAxisAlignment: CrossAxisAlignment.stretch,
            children: [
              Container(
                padding: const EdgeInsets.all(12),
                color: Colors.red.shade300,
                child: const Text('Row 1', style: TextStyle(color: Colors.white, fontSize: 16)),
              ),
              const SizedBox(height: 8),
              Container(
                padding: const EdgeInsets.all(12),
                color: Colors.red.shade400,
                child: const Text('Row 2', style: TextStyle(color: Colors.white, fontSize: 16)),
              ),
              const SizedBox(height: 8),
              Container(
                padding: const EdgeInsets.all(12),
                color: Colors.red.shade500,
                child: const Text('Row 3', style: TextStyle(color: Colors.white, fontSize: 16)),
              ),
            ],
          ),

          // SizedBox Widget
          const SizedBox(height: 24),
          const Text(
            'SizedBox Widget Example',
            style: TextStyle(
              fontSize: 24,
              fontWeight: FontWeight.bold,
              color: Colors.deepPurple,
            ),
          ),
          const SizedBox(height: 8),
          SizedBox(
            height: 100,
            child: Container(
              color: Colors.teal.shade100,
              child: const Center(
                child: Text(
                  'This SizedBox has a fixed height of 100',
                  style: TextStyle(fontSize: 16, color: Colors.teal),
                  textAlign: TextAlign.center,
                ),
              ),
            ),
          ),

          const SizedBox(height: 32),
        ],
      ),
    );
  }
}
