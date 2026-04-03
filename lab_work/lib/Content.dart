import 'package:flutter/material.dart';
import 'package:lab_work/configurations.dart';

enum ToggleMode { direct, dialog }

class Content extends StatefulWidget {
  @override
  State<StatefulWidget> createState() => ContentState();
}

class ContentState extends State<Content> {
  ToggleMode _currentMode = ToggleMode.direct;

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        leading: BackButton(),
        backgroundColor: Theme.of(context).colorScheme.inversePrimary,
        title: Text("Content"),
      ),
      body: Column(
        children: [
          // Dropdown to switch between Direct and Dialog modes
          Padding(
            padding: const EdgeInsets.all(8.0),
            child: Row(
              mainAxisAlignment: MainAxisAlignment.center,
              children: [
                DropdownButton<ToggleMode>(
                  value: _currentMode,
                  items: const [
                    DropdownMenuItem(
                      value: ToggleMode.direct,
                      child: Text("Direct"),
                    ),
                    DropdownMenuItem(
                      value: ToggleMode.dialog,
                      child: Text("Dialog"),
                    ),
                  ],
                  onChanged: (ToggleMode? newMode) {
                    if (newMode != null) {
                      setState(() {
                        _currentMode = newMode;
                      });
                    }
                  },
                ),
              ],
            ),
          ),
          // Expanded ListView so it takes up the remaining screen space
          Expanded(
            child: ListView.builder(
              itemCount: Configurations.attendance.length,
              itemBuilder: (context, index) {
                String date = Configurations.attendance[index][0].toString();
                int initialStatus = Configurations.attendance[index][1] as int;

                return AttendanceItem(
                  index: index,
                  date: date,
                  initialStatus: initialStatus,
                  mode: _currentMode,
                );
              },
            ),
          ),
        ],
      ),
    );
  }
}

// Extracted StatefulWidget to localize setState rebuilds
class AttendanceItem extends StatefulWidget {
  final int index;
  final String date;
  final int initialStatus;
  final ToggleMode mode;

  const AttendanceItem({
    Key? key,
    required this.index,
    required this.date,
    required this.initialStatus,
    required this.mode,
  }) : super(key: key);

  @override
  State<AttendanceItem> createState() => _AttendanceItemState();
}

class _AttendanceItemState extends State<AttendanceItem> {
  late bool isPresent;

  @override
  void initState() {
    super.initState();
    // 1 for Present, 0 for Absent
    isPresent = widget.initialStatus == 1;
  }

  void toggleStatus() {
    setState(() {
      isPresent = !isPresent;
    });
    // Persist to the static list so it survives navigation during this session
    Configurations.attendance[widget.index][1] = isPresent ? 1 : 0;
  }

  void handleTap() {
    if (widget.mode == ToggleMode.direct) {
      toggleStatus();
    } else {
      showDialog(
        context: context,
        barrierDismissible: false, // Forces user to click a button
        builder: (BuildContext context) {
          return AlertDialog(
            title: const Center(child: Icon(Icons.edit_note, size: 40)),
            content: const Text(
              'Edit Attendance',
              textAlign: TextAlign.center,
              style: TextStyle(fontSize: 20),
            ),
            actionsAlignment: MainAxisAlignment.spaceEvenly,
            actions: [
              TextButton(
                onPressed: () {
                  Navigator.pop(context); // Close Dialog
                  toggleStatus();         // Apply Change
                },
                child: const Text('Change', style: TextStyle(color: Colors.deepPurple)),
              ),
              TextButton(
                onPressed: () {
                  Navigator.pop(context); // Close Dialog without changing
                },
                child: const Text('Cancel', style: TextStyle(color: Colors.red)),
              ),
            ],
          );
        },
      );
    }
  }

  @override
  Widget build(BuildContext context) {
    return Container(
      margin: const EdgeInsets.all(10),
      child: Row(
        mainAxisAlignment: MainAxisAlignment.spaceAround,
        children: [
          Text(widget.date, style: const TextStyle(fontSize: 20)),
          InkWell(
            onTap: handleTap,
            child: CircleAvatar(
              backgroundColor: isPresent ? Colors.green : Colors.red,
              child: Text(
                isPresent ? "P" : "A",
                style: isPresent ? const TextStyle(color: Colors.black) : const TextStyle(color: Colors.white),
              ),
            ),
          ),
        ],
      ),
    );
  }
}